/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/07/15 16:09:47 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::cerr;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(void)
{
	cout << BLUE << "Bureaucrat tests" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << YELLOW << "Test 1: Bureaucrat creation:" << RESET << endl;

	cout << endl;

	Bureaucrat alan("Alan", 50);

	cout << alan << endl;

	try {
		alan.promotion();
	}
	catch (std::exception &e) {
		cerr << e.what() << endl;
	}

	cout << alan << endl;

	try {
		alan.demotion();
	}
	catch (std::exception &e) {
		cerr << RED << e.what() << RESET << endl;
	}

	cout << alan << endl;

	cout << YELLOW <<  "End of Test 1" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << YELLOW << "Test 2: Bureaucrat demotion impossible" << RESET << endl;

	Bureaucrat bob("Bob", 150);

	cout << bob << endl;

	try {
		bob.demotion();
	}
	catch (std::exception &e) {
		cerr << RED << e.what() << RESET << endl;
	}

	cout << bob << endl;

	cout << YELLOW << "End of Test 2" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << YELLOW << "Test 3: Bureaucrat promotion impossible" << RESET << endl;

	Bureaucrat charlie("Charlie", 1);
	
	cout << charlie << endl;

	try {
		charlie.promotion();
	}
	catch (std::exception &e) {
		cerr << RED << e.what() << RESET << endl;
	}

	cout << charlie << endl;

	cout << YELLOW << "End of Test 3" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << YELLOW << "Test 4: Bureaucrat creation with grade too high" << RESET << endl;

	try {
		Bureaucrat daniel("Daniel", 0);
	}
	catch (std::exception &e) {
		cerr << RED << e.what() << RESET << endl;

	}

	cout << YELLOW << "End of Test 4" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << YELLOW << "Test 5: Bureaucrat creation with grade too low" << RESET << endl;
	
	try {
		Bureaucrat edward("Edward", 151);
	}
	catch (std::exception &e) {
		cerr << RED << e.what() << RESET << endl;
	}
	
	cout << YELLOW << "End of Test 5" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << BLUE << "End of Bureaucrat tests" << RESET << endl;

	return (0);
}