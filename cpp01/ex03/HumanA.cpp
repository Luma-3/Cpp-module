/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:10:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:20:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) : name(name), weapon(weapon) {};

HumanA::~HumanA() {};

void HumanA::attack()
{
	cout << name + "attacks with their" + weapon.getType() << endl;
}