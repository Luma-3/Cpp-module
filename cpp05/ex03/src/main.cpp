/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 15:09:05 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#include <sstream>

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
	cout << BLUE << "Intern tests" << RESET << endl;
	cout << "----------------" << endl;
	
	TEST(1, "Create a form", {
		Intern intern;
		AForm *form = intern.makeForm("Shrubbery Creation", "home");
		EXPECT_EQ(form->getName(), "Shrubbery Creation Form");
		EXPECT_EQ(form->getTarget(), "home");
		delete form;
	});

	TEST(2, "Create a form", {
		Intern intern;
		AForm *form = intern.makeForm("Robotomy Request", "office");
		EXPECT_EQ(form->getName(), "Robotomy Request Form");
		EXPECT_EQ(form->getTarget(), "office");
		delete form;
	});

	TEST(3, "Create a form", {
		Intern intern;
		AForm *form = intern.makeForm("Presidential Pardon", "home");
		EXPECT_EQ(form->getName(), "Presidential Pardon Form");
		EXPECT_EQ(form->getTarget(), "home");
		delete form;
	});

	TEST(4, "Create a form", {
		Intern intern;
		AForm *form = intern.makeForm("Unknown", "home");
		EXPECT_EQ(form, 0);
	});

	cout << "----------------" << endl;
	cout << BLUE << "End Intern tests" << RESET << endl;
	
	
	return (0);
}