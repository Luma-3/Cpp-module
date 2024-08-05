/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:11:01 by luma              #+#    #+#             */
/*   Updated: 2024/08/05 16:06:23 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>


using std::cout;
using std::string;
using std::endl;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (this != &src) {
		*this = src;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// Exception

const char *ScalarConverter::IsImpossibleException::what() const throw() {
	return ("Is Impossible");
}

const char *ScalarConverter::NotDisplayableException::what() const throw() {
	return ("Not Displayable");
}

// MakeConvert 


//////////////////
// Verification //
//////////////////

static bool isValideNumber(char c) {
	if (isdigit(c) || c == '.' || c == '-' || c == '+') {
		return (true);
	}
	return (false);
}

static bool ft_isSingleChar(const string &str) {
	if (str.length() == 1 && isalpha(str[0])) {
		return (true);
	}
	return (false);
}

static bool verifPrompt(const string &prompt) {
	
	if (prompt.length() == 1 && isprint(prompt[0]) && !isdigit(prompt[0])) {
		return (true);
	}
	
	string valid_str[] = {"nan", "nanf", "-inf", "inf", "-inff", "inff", "+inf", "+inff"};

	for (size_t i = 0; i < 8; i++)
	{
		if (prompt == valid_str[i]) {
			return (true);
		}
	}
	
	for (size_t i = 0; i < prompt.length() ; ++i)
	{
		if (isValideNumber(prompt[i]) == false) {
			return (false);
		}
	}
	
	return (true);
}

static bool isNaN(double value) {
	return (value != value);
}


static bool isInfinite(double value) {
	return (fabs(value) == std::numeric_limits<double>::infinity());
}


/////////////
// Casting //
/////////////

static int castToInt(long double d) {
	long i = static_cast<long>(d);
	
	if (isInfinite(d) || isNaN(d)
	|| i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		throw (ScalarConverter::IsImpossibleException());
	}
	return (static_cast<int>(i));
}

static float castToFloat(long double d) {
	if ((d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max()) 
	&& !(isInfinite(d) || !isNaN(d))) {
		throw (ScalarConverter::IsImpossibleException());
	}
	return (static_cast<float>(d));
}

static double castToDouble(long double d) {
	if ((d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
	&& !(isInfinite(d) || !isNaN(d))) {
		throw (ScalarConverter::IsImpossibleException());
	}
	return (static_cast<double>(d));
}

static char castToChar(long double d) {
	char c = static_cast<char>(d);
	if (isInfinite(d) || isNaN(d)
	|| d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		throw (ScalarConverter::IsImpossibleException());
	}
	if (!isprint(c)) {
		throw (ScalarConverter::NotDisplayableException());
	}
	return (c);
}

///////////
// Print //
///////////


static void printInt(long double d) {
	cout << "Int: ";
	try {
		cout << castToInt(d) << endl;
	}
	catch (std::exception & e) {
		cout << e.what() << endl;
	}
}

static void printFloat(long double d) {
	cout << "Float: ";
	try {
		cout << castToFloat(d) << "f" << endl;
	}
	catch (std::exception & e) {
		cout << e.what() << endl;
	}
}

static void printDouble(long double d) {
	cout << "Double: ";
	try {
		cout << castToDouble(d) << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}
}

static void printChar(long double d) {
	cout << "Char: ";
	try {
		cout << castToChar(d) << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}
}


void ScalarConverter::convert(const string str) {

	if (verifPrompt(str) == false) {
		cout << "Input Invalid" << endl;
		return ;
	}

	long double convertedNumber;

	if (ft_isSingleChar(str) == true) {
		convertedNumber = static_cast<long double>(str[0]);
	}
	else {
		convertedNumber = strtold(str.c_str(), NULL);
	}

	cout << std::fixed << std::setprecision(1);
	printChar(convertedNumber);
	printInt(convertedNumber);
	printFloat(convertedNumber);
	printDouble(convertedNumber);
}