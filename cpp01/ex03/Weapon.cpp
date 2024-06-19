/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:50:10 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:22:31 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type) : type(type) {};

Weapon::~Weapon() {};

const string &Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(string type_p)
{
	type = type_p;
}