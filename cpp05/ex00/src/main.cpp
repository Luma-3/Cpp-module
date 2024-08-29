/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 13:35:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define EXPECT_EQ(a, b) (a == b ?	cout << GREEN << "[ OK ]" << endl << RESET :\
									cout << RED << "[ KO ]" << endl << "Expected: " << b << " | Got: " << a << endl << RESET)

#define TEST(id, name, code) cout << YELLOW << "Test " << id << ": " << name << RESET << endl; code

int main(void)
{
	cout << BLUE << "Bureaucrat tests" << RESET << endl;
	cout << "----------------" << endl;
	cout << endl;

	TEST("1", "Create Bureaucrat with Correct information", {
		Bureaucrat bureaucrat("bureaucrat", 1);
		EXPECT_EQ(bureaucrat.getName(), "bureaucrat");
		EXPECT_EQ(bureaucrat.getGrade(), 1);
	});

	TEST("2", "Create Bureaucrat with Too Low Grade", {
		try {
			Bureaucrat bureaucrat("bureaucrat", 151);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too low");
		}
	});

	TEST("3", "Create Bureaucrat with Too High Grade", {
		try {
			Bureaucrat bureaucrat("bureaucrat", 0);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too high");
		}
	});

	TEST("4", "Promote Bureaucrat", {
		Bureaucrat bureaucrat("bureaucrat", 150);
		bureaucrat.promotion();
		EXPECT_EQ(bureaucrat.getGrade(), 149);
	});

	TEST("5", "Demote Bureaucrat", {
		Bureaucrat bureaucrat("bureaucrat", 2);
		bureaucrat.demotion();
		EXPECT_EQ(bureaucrat.getGrade(), 3);
	});

	TEST("6", "Promote Bureaucrat with Too High Grade", {
		Bureaucrat bureaucrat("bureaucrat", 1);
		try {
			bureaucrat.promotion();
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too high");
		}
	});

	TEST("7", "Demote Bureaucrat with Too Low Grade", {
		Bureaucrat bureaucrat("bureaucrat", 150);
		try {
			bureaucrat.demotion();
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too low");
		}
	});

	cout << "----------------" << endl;
	cout << endl;
	cout << BLUE << "End of Bureaucrat tests" << RESET << endl;

	return (0);
}