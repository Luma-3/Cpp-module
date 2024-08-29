/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:26 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 10:35:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

using std::cout;
using std::endl;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Ice::Ice() : AMateria("ice") {
	cout << GREEN << "Ice created by Default constructor" << RESET << endl;
}

Ice::Ice(const Ice & src) : AMateria(src) {
	cout << GREEN << "Ice created by Copy constructor" << RESET << endl;
	*this = src;
}

Ice & Ice::operator=(const Ice & src) {
	cout << YELLOW << "Ice created by Assignation operator" << RESET << endl;
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

Ice::~Ice() {
	cout << RED << "Ice destroyed" << RESET << endl;
}

AMateria* Ice::clone() const {
	cout << "Ice cloned" << endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << endl;
}