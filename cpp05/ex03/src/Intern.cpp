/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:06:53 by luma              #+#    #+#             */
/*   Updated: 2024/08/04 18:09:41 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	if (this != &src) {
		*this = src;
	}
	return *this;
}

Intern::~Intern() {}


static AForm *createShrubberyCreationForm(const string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyRequestForm(const string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialPardonForm(const string target) {
	return (new PresidentialPardonForm(target));
}


AForm *Intern::makeForm(const string name, const string target) {
	
	typedef AForm* ( *func)(const string target);
	typedef struct {
		string name;
		func _func;
	}		formCreator;

	const formCreator available_form[] = {
		{"Shrubbery Creation", &createShrubberyCreationForm},
		{"Robotomy Request", &createRobotomyRequestForm},
		{"Presidential Pardon", &createPresidentialPardonForm}
	};


	for(size_t i = 0; i <= 2; ++i) {
		if (name == available_form[i].name) {
			std::cout << "Intern creates " << name << std::endl;
			return (available_form[i]._func(target));
		}
	}

	std::cout << "Form " << name << " not found" << std::endl;
	return (NULL);
}
