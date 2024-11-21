/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:03:46 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 12:49:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", "unknown", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery Creation Form", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	AForm(src)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		AForm::operator=(*this);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	checkExectionRequirement(executor);

	std::fstream file((this->getTarget() + "_shrubbery").c_str(), std::ios::out);

	if (file.is_open()) {
		file << "                  %%%,%%%%%%%" << endl;
		file << "                   ,'%% \\\\-*%%%%%%%" << endl;
		file << "             ;%%%%%*%   _%%%%" << endl;
		file << "              ,%%%       \(_.*%%%%." << endl;
		file << "              % *%%, ,%%%%*(    '" << endl;
		file << "            %^     ,*%%% )\\|,%%*%,_" << endl;
		file << "                 *%    \\/ #).-\"*%%*\"" << endl;
		file << "                     _.) ,/ *%," << endl;
		file << "             _________/)#(_____________" << endl;
		file.close();
	}
}