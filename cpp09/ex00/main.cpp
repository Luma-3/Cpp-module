/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:07:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/29 17:07:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>

#include "BitcoinExchange.hpp"

static void read_file(const std::string &file_path, BitcoinExchange &exchange)
{
	std::string	  line;
	std::ifstream file(file_path.c_str(), std::ios::in);

	if (file.fail()) {
		throw BitcoinExchange::FileOpenException(file_path, file);
	}

	std::getline(file, line);
	if (line.empty()) {
		throw BitcoinExchange::InvalidFormatFile("No format start line");
	}
	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t pos_separator = line.find("|");

		if (pos_separator == std::string::npos) {
			std::cout << "Error: Bad input => " << line << std::endl;
			continue;
		}

		std::string key =
			BitcoinExchange::trimSpace(line.substr(0, pos_separator));
		std::string value =
			BitcoinExchange::trimSpace(line.substr(pos_separator + 1));

		exchange.findAndDisplay(key, strtod(value.c_str(), NULL));
	}
}

int main(int ac, char **av)
{

	if (ac != 2) {
		std::cout << "Error No file Specified" << std::endl;
	}

	try {
		BitcoinExchange exchange;
		read_file(av[1], exchange);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
}