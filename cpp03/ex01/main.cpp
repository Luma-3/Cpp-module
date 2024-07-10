/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/10 13:48:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap warrior("Michel");
	warrior.setAttackDamage(5);

	ScavTrap a1("Jack");

	a1.attack("Michel");
	
	warrior.takeDamage(a1.getAttackDamage());
	a1.guardGate();

	warrior.attack("Jack");
	a1.takeDamage(warrior.getAttackDamage());
	
		
	return 0;
}