/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/03 20:19:16 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::cerr;

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
	cout << BLUE << "Shrubbery tests" << RESET << endl;
	cout << "----------------" << endl;
	
	TEST(1, "Create ShrubberyCreationForm", {
		ShrubberyCreationForm form("Home");
		EXPECT_EQ(form.getName(), "Shrubbery Creation Form");
		EXPECT_EQ(form.getTarget(), "Home");
		EXPECT_EQ(form.getGradeToSign(), 145);
		EXPECT_EQ(form.getGradeToExecute(), 137);
		EXPECT_EQ(form.isSigned(), false);
	});

	TEST(2, "Create Bureaucrat", {
		Bureaucrat bureaucrat("Bureaucrat", 150);
		EXPECT_EQ(bureaucrat.getName(), "Bureaucrat");
		EXPECT_EQ(bureaucrat.getGrade(), 150);
	});

	TEST(3, "Sign ShrubberyCreationForm", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 150);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), false);
	});

	TEST(4, "Sign ShrubberyCreationForm with a Bureaucrat with a grade of 145", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 145);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});

	TEST(5, "Sign ShrubberyCreationForm with a Bureaucrat with a grade of 137", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 137);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});
	
	cout << endl << RED << "Manual tests for Execute Form" << RESET << endl << endl;	

	TEST(6, "Execute ShrubberyCreationForm with a Bureaucrat with a grade of 150", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat1("Bureaucrat", 145);
		bureaucrat1.signForm(form);
		Bureaucrat bureaucrat2("Bureaucrat", 150);
		cout << BLUE << "GOT : " << RESET << endl;
		bureaucrat2.executeForm(form);
		cout << BLUE << "Expected : " << RESET << endl << "Bureaucrat cannot execute Shrubbery Creation Form because: Grade is too low" << endl;
	});

	TEST(7, "Execute ShrubberyCreationForm with Form is not signed", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 145);
		cout << BLUE << "GOT : " << RESET << endl;
		bureaucrat.executeForm(form);
		cout << BLUE << "Expected : " << RESET << endl << "Bureaucrat cannot execute Shrubbery Creation Form because: Form is not signed" << endl;
	});

	TEST(8, "Execute ShrubberyCreationForm Correctly", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 137);
		bureaucrat.signForm(form);
		cout << BLUE << "GOT : " << RESET << endl;
		bureaucrat.executeForm(form);
		cout << BLUE << "Expected : " << RESET << endl << "Bureaucrat execute Shrubbery Creation Form" << endl;
	});

	cout << "----------------" << endl;
	cout << BLUE << "End of Shruberry tests" << RESET << endl;
	
	return (0);
}