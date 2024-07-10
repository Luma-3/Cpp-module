/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/10 12:44:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap warrior;
	warrior.setAttackDamage(5);
	warrior.setHitPoint(10);
	warrior.setEnergyPoint(5);
	warrior.setName("Gorge");

	ClapTrap armoredWarrior("Michel");
	armoredWarrior.setAttackDamage(5);
	armoredWarrior.setHitPoint(50);
	
	ClapTrap warrior2(warrior);
	
	warrior2.setName("Jack");

	ClapTrap armoredWarrior2;
	armoredWarrior2 = armoredWarrior;

	armoredWarrior2.setName("val");
	
	warrior2.setAttackDamage(10);

	warrior.attack("Michel");
	armoredWarrior.takeDamage(warrior.getAttackDamage());
	armoredWarrior.beRepaired(5);

	armoredWarrior2.attack("Jack");
	warrior2.takeDamage(armoredWarrior2.getAttackDamage());

	warrior2.attack("Gorge");
	warrior.takeDamage(warrior2.getAttackDamage());

	warrior.attack("Michel");

	return 0;
}