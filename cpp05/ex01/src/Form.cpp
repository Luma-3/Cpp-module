/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:45:04 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 13:37:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::endl;

Form::Form() :
	_name("unknown"),
	_is_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1)
{}

Form::Form(const Form &src) : 
	_name(src._name),
	_is_signed(src._is_signed),
	_grade_to_sign(src._grade_to_sign),
	_grade_to_execute(src._grade_to_execute)
{}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
	}
	return *this;
}

Form::~Form() {

}

Form::Form(const std::string name, const int grade_sign, const int grade_exec) :
	_name(name),
	_is_signed(false),
	_grade_to_sign(grade_sign),
	_grade_to_execute(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
	{
		throw (GradeTooHighException());
	}
	else if (grade_sign > 150 || grade_exec > 150)
	{
		throw (GradeTooLowException());
	}
}

std::string Form::getName() const {
	return (_name);
}

bool Form::isSigned() const {
	return (_is_signed);
}

int Form::getGradeToSign() const {
	return (_grade_to_sign);
}

int Form::getGradeToExecute() const {
	return (_grade_to_execute);
}

void Form::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= _grade_to_sign){
		_is_signed = true;
	}
	else {
		throw (GradeTooLowException());
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}


std::ostream &operator<<(std::ostream& out, const Form &form) {
	out << "Form " << form.getName();

	if (form.isSigned() == true) {
		out << "is Signed." << endl;
	}
	else {
		out << "isn't Signed." << endl;
	}
	
	out << "Minimum Grade to sign form is: " << form.getGradeToSign()<< endl;
	out << "Minimum Grade to Execute form is: " << form.getGradeToExecute() << endl;
	return (out);
}
