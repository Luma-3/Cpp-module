/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:32 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/29 17:04:55 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream db_file(DB_PATH);
	if (db_file.is_open() == false) {
		throw FileOpenException(_file_path, db_file);
	}

	readData(db_file);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db(src._db) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs) {
		_db = rhs._db;
	}
	return (*this);
}

void BitcoinExchange::readData(std::ifstream &db_file)
{
	std::string line;

	std::getline(db_file, line);
	if (line.empty()) {
		throw InvalidFormatFile("No format start line");
	}
	while (std::getline(db_file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t pos_separator = line.find(",");

		if (pos_separator == std::string::npos) {
			throw InvalidFormatFile("No separator in line");
		}

		std::string key = trimSpace(line.substr(0, pos_separator));
		std::string value = trimSpace(line.substr(pos_separator + 1));

		validateDate(key);

		_db[key] = strtod(value.c_str(), NULL);
	}
}

std::string BitcoinExchange::trimSpace(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t\r");
	if (start == std::string::npos) {
		return "";
	}
	size_t end = str.find_last_not_of(" \t\r");

	return str.substr(start, end - start + 1);
}

void BitcoinExchange::validateDate(const std::string &date)
{
	if (date.size() != 10) {
		throw InvalidFormatFile("Invalide Date, size not correct");
	}

	int				  year, month, day;
	char			  dash1, dash2;
	std::stringstream ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-') {
		throw InvalidFormatFile("Invalide Date, Format not match");
	}

	if (month < 1 || month > 12 || day < 1 || day > 31) {
		throw InvalidFormatFile("Invalide Date, month or day range");
	}

	int day_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		day_in_month[1] = 29;
	}

	if (day > day_in_month[month - 1]) {
		throw InvalidFormatFile("Invalide Date, too many day in month");
	}
}

void BitcoinExchange::findAndDisplay(const std::string &date, float value)
{
	try {
		validateDate(trimSpace(date));
	} catch (std::exception &e) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	else if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	float mult;
	if (_db.find(date) != _db.end()) {
		mult = _db[date];
	}
	else {
		std::map< std::string, float >::iterator it = _db.lower_bound(date);
		if (it == _db.begin()) {
			std::cout << "Error: No Lower value for this requested date"
					  << std::endl;
			return;
		}
		--it;
		mult = it->second;
	}
	double result = value * mult;

	std::cout << date << " => " << value << " = " << result << std::endl;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////		EXCEPTION		////////////////////////////
//////////////////////////////////////////////////////////////double//////////////

BitcoinExchange::FileOpenException::FileOpenException(
	const std::string &file_path, const std::ifstream &file) :
	std::runtime_error("FileOpenExecption: " + file_path +
					   "could not open due to " + getFileErrorMessage(file))
{
}

std::string BitcoinExchange::FileOpenException::getFileErrorMessage(
	const std::ifstream &file)
{
	if (file.bad()) return "badbit error";
	if (file.fail()) return "failbit error";
	return "unknown error";
}

BitcoinExchange::InvalidFormatFile::InvalidFormatFile(const std::string &msg) :
	std::runtime_error(msg)
{
}