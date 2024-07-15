/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:09:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 23:07:00 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure & src) : AMateria(src) {}

Cure & Cure::operator=(const Cure & src) {
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}