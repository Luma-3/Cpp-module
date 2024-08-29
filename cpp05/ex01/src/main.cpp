/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 13:35:40 by jbrousse         ###   ########.fr       */
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
	cout << BLUE << "Form tests" << RESET << endl;
	cout << "----------------" << endl;
	
	TEST("1", "Create Form with Correct information", {
		Form form("form", 1, 1);
		EXPECT_EQ(form.getName(), "form");
		EXPECT_EQ(form.getGradeToSign(), 1);
		EXPECT_EQ(form.getGradeToExecute(), 1);
	});

	TEST("2", "Create Form with Too Low Sign-Grade", {
		try {
			Form form("form", 151, 1);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too low");
		}
	});

	TEST("3", "Create Form with Too High Sign-Grade", {
		try {
			Form form("form", 0, 1);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too high");
		}
	});

	TEST("4", "Create Form with Too Low Execute-Grade", {
		try {
			Form form("form", 1, 151);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too low");
		}
	});

	TEST("5", "Create Form with Too High Execute-Grade", {
		try {
			Form form("form", 1, 0);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too high");
		}
	});

	TEST("6", "Create Form with Correct information and Sign it", {
		Form form("form", 1, 1);
		Bureaucrat bureaucrat("bureaucrat", 1);
		form.beSigned(bureaucrat);
		EXPECT_EQ(form.isSigned(), true);
	});

	TEST("7", "Create Form with Correct information and Sign it with Too Low Grade", {
		Form form("form", 1, 1);
		Bureaucrat bureaucrat("bureaucrat", 2);
		try {
			form.beSigned(bureaucrat);
		} catch (std::exception &e) {
			EXPECT_EQ(string(e.what()), "Grade is too low");
		}
	});

	cout << "----------------" << endl;
	cout << BLUE << "End of Form tests" << RESET << endl;
	
	return (0);
}