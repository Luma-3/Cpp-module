/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:00:13 by luma              #+#    #+#             */
/*   Updated: 2024/08/03 22:00:28 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", "unknown", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const string target) :
	AForm("Presidential Pardon Form", target, 25, 5)
{}	


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
	: AForm(src)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExectionRequirement(executor);
	cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << endl;
}