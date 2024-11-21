/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 10:13:14 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	FragTrap Default;

	FragTrap a("FragTrap1");
	FragTrap b("FragTrap2");
	
	cout << "----------------" << endl << endl;

	a.attack("FragTrap2");
	b.takeDamage(a.getAttackDamage());

	b.attack("FragTrap1");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(5);


	cout << "Name a: " << a.getName() << endl;
	cout << "----------------" << endl;
	cout << "Attack a: " << a.getAttackDamage() << endl;
	cout << "Hit point a: " << a.getHitPoint() << endl;
	cout << "Energy point a: " << a.getEnergyPoint() << endl;
	cout << "----------------" << endl << endl;

	cout << "Name b: " << b.getName() << endl;
	cout << "----------------" << endl;
	cout << "Attack b: " << b.getAttackDamage() << endl;
	cout << "Hit point b: " << b.getHitPoint() << endl;
	cout << "Energy point b: " << b.getEnergyPoint() << endl;
	cout << "----------------" << endl << endl;

	cout << "----------------" << endl;
	cout << "Spec methode" << endl;
	cout << "----------------" << endl;

	a.highFivesGuys();

	cout << "----------------" << endl;
	cout << "Limit test" << endl;
	cout << "----------------" << endl;

	FragTrap c("FragTrap3");
	c.takeDamage(55);
	c.takeDamage(50);
	c.takeDamage(5);
	cout << "Hit point c: " << c.getHitPoint() << endl;

	cout << "----------------" << endl;
		
	return 0;
}