/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:43:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 16:32:03 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

AMateria::AMateria() : type("unknown") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria & src) : type(src.type) {
}

AMateria & AMateria::operator=(const AMateria & src) {
	if (this != &src) {
		type = src.type;
	}
	return *this;
}

AMateria::~AMateria() {}

string const & AMateria::getType() const {
	return type;
}

// void AMateria::use(ICharacter & target) {
// 	cout << " Use called " << endl;
// }

