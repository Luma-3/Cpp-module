/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:43:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 23:03:42 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria & src) : _type(src._type) {
}

AMateria & AMateria::operator=(const AMateria & src) {
	if (this != &src) {
		_type = src._type;
	}
	return *this;
}

AMateria::~AMateria() {}

string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	cout << " Use called on " << target.getName() << endl;
}

