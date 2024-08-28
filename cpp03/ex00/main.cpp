/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:20:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 09:50:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	ClapTrap Default;

	ClapTrap a("Michel");

	ClapTrap b("Jean");

	cout << "----------------" << endl << endl;

	a.attack("Jean");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	b.attack("Michel");
	a.takeDamage(b.getAttackDamage());

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
	cout << "----------------" << endl;

	cout << "----------------" << endl;
	cout << "Limit test" << endl;
	cout << "----------------" << endl;
	
	ClapTrap c("Jean");
	c.takeDamage(10);
	c.takeDamage(10);
	cout << "Hit point c: " << c.getHitPoint() << endl;

	ClapTrap d("Jean");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	d.attack("Michel");
	cout << d.getEnergyPoint() << endl;

	cout << "----------------" << endl << endl;
	

	return 0;
}