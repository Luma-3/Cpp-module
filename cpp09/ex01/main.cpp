/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:05:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/02 17:20:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "RPN.hpp"

void parse(std::string &str, RPN &rpn)
{
	std::stringstream ss(str);

	while (ss) {
		std::string token;
		ss >> token;

		if (token.empty()) {
			break;
		}

		if (token.length() == 1 && isdigit(token[0])) {
			rpn.push(atoi(token.c_str()));
		}
		else if (token.length() == 1 && RPN::isOperator(token[0])) {
			rpn.calculate(token[0]);
		}
		else {
			throw std::runtime_error(
				"invalid expression (invalid token : " + token + ")");
		}
	}
}
int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
		return 1;
	}

	RPN rpn;

	std::string input = argv[1];

	try {
		parse(input, rpn);
		std::cout << rpn.takeResult() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
