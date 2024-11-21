/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 11:11:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main(void)
{
	DiamondTrap Default;

	DiamondTrap a("DiamondTrap1");
	DiamondTrap b("DiamondTrap2");
	
	cout << GREEN <<  "----------------" << endl;
	cout << "Combat" << endl;
	cout << "----------------" << RESET <<endl << endl;

	a.attack("DiamondTrap2");
	b.takeDamage(a.getAttackDamage());

	b.attack("DiamondTrap1");
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
	a.guardGate();
	a.whoAmI();

	return 0;
}