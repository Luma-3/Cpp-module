/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:09:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 10:36:48 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using std::cout;
using std::endl;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Cure::Cure() : AMateria("cure") {
	cout << GREEN << "Cure created by Default constructor" << RESET << endl;
}

Cure::Cure(const Cure & src) : AMateria(src) {
	cout << GREEN << "Cure created by Copy constructor" << RESET << endl;
	*this = src;
}

Cure & Cure::operator=(const Cure & src) {
	cout << YELLOW << "Cure created by Assignation operator" << RESET << endl;
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

Cure::~Cure() {
	cout << RED << "Cure destroyed" << RESET << endl;
}

AMateria* Cure::clone() const {
	cout << "Cure cloned" << endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	cout << BLUE << "* heals " << target.getName() << "'s wounds *" << RESET << endl;
}