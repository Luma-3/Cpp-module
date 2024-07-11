/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:26 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 17:59:29 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice & src) : AMateria(src) {}

Ice & Ice::operator=(const Ice & src) {
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}