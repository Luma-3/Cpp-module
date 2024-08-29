/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 13:35:37 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

#define EXPECT_OUTPUT_EQ(code, expected_output) { \
    std::streambuf* old_buf = std::cout.rdbuf(); \
    std::ostringstream capture; \
    std::cout.rdbuf(capture.rdbuf()); \
    code; \
    std::cout.rdbuf(old_buf); \
    EXPECT_EQ(capture.str(), expected_output); \
}

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
	
	cout << endl << RED << "Execute tests Form" << RESET << endl << endl;	

	TEST(6, "Execute ShrubberyCreationForm with a Bureaucrat with a grade of 150", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat1("Bureaucrat", 145);
		bureaucrat1.signForm(form);
		Bureaucrat bureaucrat2("Bureaucrat", 150);
		EXPECT_OUTPUT_EQ(bureaucrat2.executeForm(form), "Bureaucrat cannot execute Shrubbery Creation Form because: Grade is too low\n");
	});

	TEST(7, "Execute ShrubberyCreationForm with Form is not signed", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 145);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Bureaucrat cannot execute Shrubbery Creation Form because: Form is not signed\n");
	});

	TEST(8, "Execute ShrubberyCreationForm Correctly", {
		ShrubberyCreationForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 137);
		bureaucrat.signForm(form);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Bureaucrat executed Shrubbery Creation Form\n");
	});

	cout << "----------------" << endl;
	cout << BLUE << "End of Shruberry tests" << RESET << endl;

	
	cout << endl << BLUE << "Robotomy tests" << RESET << endl;
	cout << "----------------" << endl;

	TEST(1, "Create RobotomyRequestForm", {
		RobotomyRequestForm form("Home");
		EXPECT_EQ(form.getName(), "Robotomy Request Form");
		EXPECT_EQ(form.getTarget(), "Home");
		EXPECT_EQ(form.getGradeToSign(), 72);
		EXPECT_EQ(form.getGradeToExecute(), 45);
		EXPECT_EQ(form.isSigned(), false);
	});

	TEST(2, "Create Bureaucrat", {
		Bureaucrat bureaucrat("Bureaucrat", 150);
		EXPECT_EQ(bureaucrat.getName(), "Bureaucrat");
		EXPECT_EQ(bureaucrat.getGrade(), 150);
	});

	TEST(3, "Sign RobotomyRequestForm", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 150);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), false);
	});

	TEST(4, "Sign RobotomyRequestForm with a Bureaucrat with a grade of 72", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 72);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});

	TEST(5, "Sign RobotomyRequestForm with a Bureaucrat with a grade of 45", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 45);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});

	cout << endl << RED << "Execute tests Form" << RESET << endl << endl;

	TEST(6, "Execute RobotomyRequestForm with a Bureaucrat with a grade of 150", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat1("Bureaucrat", 72);
		bureaucrat1.signForm(form);
		Bureaucrat bureaucrat2("Bureaucrat", 150);
		EXPECT_OUTPUT_EQ(bureaucrat2.executeForm(form), "Bureaucrat cannot execute Robotomy Request Form because: Grade is too low\n");
	});

	TEST(7, "Execute RobotomyRequestForm with Form is not signed", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 72);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Bureaucrat cannot execute Robotomy Request Form because: Form is not signed\n");
	});

	TEST(8, "Execute RobotomyRequestForm Correctly", {
		RobotomyRequestForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 45);
		bureaucrat.signForm(form);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Bzzzz\nHome has been robotomized successfully\nBureaucrat executed Robotomy Request Form\n");
	});

	cout << "----------------" << endl;
	cout << BLUE << "End of Robotomy tests" << RESET << endl;

	cout << endl << BLUE << "Presidential tests" << RESET << endl;
	cout << "----------------" << endl;

	TEST(1, "Create PresidentialPardonForm", {
		PresidentialPardonForm form("Home");
		EXPECT_EQ(form.getName(), "Presidential Pardon Form");
		EXPECT_EQ(form.getTarget(), "Home");
		EXPECT_EQ(form.getGradeToSign(), 25);
		EXPECT_EQ(form.getGradeToExecute(), 5);
		EXPECT_EQ(form.isSigned(), false);
	});

	TEST(2, "Create Bureaucrat", {
		Bureaucrat bureaucrat("Bureaucrat", 150);
		EXPECT_EQ(bureaucrat.getName(), "Bureaucrat");
		EXPECT_EQ(bureaucrat.getGrade(), 150);
	});
	
	TEST(3, "Sign PresidentialPardonForm", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 150);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), false);
	});	

	TEST(4, "Sign PresidentialPardonForm with a Bureaucrat with a grade of 25", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 25);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});	

	TEST(5, "Sign PresidentialPardonForm with a Bureaucrat with a grade of 5", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 5);
		bureaucrat.signForm(form);
		EXPECT_EQ(form.isSigned(), true);
	});	

	cout << endl << RED << "Execute tests Form" << RESET << endl << endl;
	
	TEST(6, "Execute PresidentialPardonForm with a Bureaucrat with a grade of 150", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat1("Bureaucrat", 25);
		bureaucrat1.signForm(form);
		Bureaucrat bureaucrat2("Bureaucrat", 150);
		EXPECT_OUTPUT_EQ(bureaucrat2.executeForm(form), "Bureaucrat cannot execute Presidential Pardon Form because: Grade is too low\n");
	});
	

	TEST(7, "Execute PresidentialPardonForm with Form is not signed", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 25);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Bureaucrat cannot execute Presidential Pardon Form because: Form is not signed\n");
	});

	TEST(8, "Execute PresidentialPardonForm Correctly", {
		PresidentialPardonForm form("Home");
		Bureaucrat bureaucrat("Bureaucrat", 5);
		bureaucrat.signForm(form);
		EXPECT_OUTPUT_EQ(bureaucrat.executeForm(form), "Home has been pardoned by Zaphod Beeblebrox\nBureaucrat executed Presidential Pardon Form\n");
	});

	cout << "----------------" << endl;
	cout << BLUE << "End of Presidential tests" << RESET << endl;
	
	return (0);
}