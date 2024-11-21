/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:43:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 10:39:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

AMateria::AMateria() : _type("unknown") {
	cout << GREEN << "AMateria created by Default constructor" << RESET << endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	cout << GREEN << "AMateria created by Param constructor" << RESET << endl;
}

AMateria::AMateria(const AMateria & src) : _type(src._type) {
	cout << GREEN << "AMateria created by Copy constructor" << RESET << endl;
	*this = src;
}

AMateria & AMateria::operator=(const AMateria & src) {
	cout << YELLOW << "AMateria created by Assignation operator" << RESET << endl;
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}

AMateria::~AMateria() {
	cout << RED << "AMateria destroyed" << RESET << endl;
}

string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	cout << " Use called on " << target.getName() << endl;
}

