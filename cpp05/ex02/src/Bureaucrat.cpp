/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:50:26 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 12:56:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this == &bureaucrat) {
		return (*this);
	}
	_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : _name(name) {
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw (GradeTooLowException());
	}
	else {
		_grade = grade;
	}
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

std::string Bureaucrat::getName() const {
	return (_name);
}

void Bureaucrat::promotion() {
	cout << "promotion" << endl;
	if (_grade - 1 < 1) {
		throw (GradeTooHighException());
	}
	_grade--;
}

void Bureaucrat::demotion(){
	cout << "demotion" << endl;
	if (_grade + 1 > 150) {
		throw (GradeTooLowException());
	}
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		cout << _name << " signed " << form.getName() << endl;
	}
	catch (std::exception &e) {
		cout << _name << " couldn't sign " << form.getName() << " because his " << e.what() << endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		cout << _name << " executed " << form.getName() << endl;
	}
	catch (std::exception &e) {
		cout << _name << " cannot execute " << form.getName() << " because: " << e.what() << endl;
	}
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	return (out);
}
