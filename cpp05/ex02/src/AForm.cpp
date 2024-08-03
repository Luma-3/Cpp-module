/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:45:04 by luma              #+#    #+#             */
/*   Updated: 2024/08/03 19:48:48 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using std::endl;

AForm::AForm() :
	_name("unknown"),
	_target("unknown"),
	_is_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1)
{}

AForm::AForm(const AForm &src) : 
	_name(src._name),
	_target(src._target),
	_is_signed(src._is_signed),
	_grade_to_sign(src._grade_to_sign),
	_grade_to_execute(src._grade_to_execute)
{}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
	}
	return *this;
}

AForm::~AForm() {

}

AForm::AForm(const string name, const string target, const int grade_sign, const int grade_exec) :
	_name(name),
	_target(target),
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

string AForm::getName() const {
	return (_name);
}

bool AForm::isSigned() const {
	return (_is_signed);
}

int AForm::getGradeToSign() const {
	return (_grade_to_sign);
}

int AForm::getGradeToExecute() const {
	return (_grade_to_execute);
}

string AForm::getTarget() const {
	return (_target);
}

void AForm::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() <= _grade_to_sign){
		_is_signed = true;
	}
	else {
		throw (GradeTooLowException());
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::FormNotSignedExecption::what() const throw() {
	return ("Form is not Signed");
}

void AForm::checkExectionRequirement(Bureaucrat const & executor) const {
	if (_is_signed == false) {
		throw (FormNotSignedExecption());
	}
	if (executor.getGrade() > _grade_to_execute) {
		throw (GradeTooLowException());
	}
}


ostream &operator<<(ostream& out, const AForm &form) {
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
