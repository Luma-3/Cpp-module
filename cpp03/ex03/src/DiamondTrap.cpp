/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:58:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:48:41 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("none") {
		cout << "DiamondTrap constructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) : 
	ClapTrap(src),
	ScavTrap(src),
	FragTrap(src),
	_name(src._name) 
{
	cout << "DiamondTrap copy constructor called" << endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & src) {
	cout << "DiamondTrap affectation operator called" << endl;
	if (this != &src) {
		_name = src._name;
		_hit_point = src._hit_point;
		_energy_point = src._energy_point;
		_attack_damage = src._attack_damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap destructor called" << endl;
}

DiamondTrap::DiamondTrap(const string &name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	cout << "DiamondTrap param contructor called" <<endl;
}

void DiamondTrap::whoAmI(void)
{
	cout << "My name is " << _name << " and my Clap name is " << ClapTrap::_name << endl;
}