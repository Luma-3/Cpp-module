/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:54:16 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 12:53:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>

#include <cstdlib>
#include <ctime>



using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", "unknown", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy Request Form", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm(src)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	checkExectionRequirement(executor);

	std::srand(std::time(0));

	if (std::rand() < RAND_MAX / 2) {
		cout << "Bzzzz" << endl;
		cout << getTarget() << " has been robotomized successfully" << endl;
	}
	else {
		cout << "Failure" << endl;
	}
}