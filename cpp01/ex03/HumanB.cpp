/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:02:17 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:27:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name) : name(name) {};

HumanB::~HumanB() {};

void HumanB::attack()
{
	if (weapon == NULL) {
		cout << name + "attacks with their hands" << endl;
	}
	else {
		cout << name + "attacks with their" + weapon->getType() << endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
