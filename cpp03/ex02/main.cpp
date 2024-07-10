/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/10 14:59:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap warrior("Michel");
	warrior.setAttackDamage(5);

	ScavTrap a1("Jack");
	FragTrap b1("Val");

	a1.attack("Michel");
	warrior.takeDamage(a1.getAttackDamage());
	
	a1.guardGate();

	warrior.attack("Jack");
	a1.takeDamage(warrior.getAttackDamage());

	b1.attack(a1.getName());
	a1.takeDamage(b1.getAttackDamage());

	b1.highFivesGuys();
	
		
	return 0;
}