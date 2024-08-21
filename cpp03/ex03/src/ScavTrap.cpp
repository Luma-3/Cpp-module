/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:39 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:48:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap() : ClapTrap() {
	cout << "ScavTrap constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src) {
	cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src) {
	cout << "ScavTrap affectation operator called" << endl;
	if (this != &src) {
		_name = src._name;
		_hit_point = src._hit_point;
		_energy_point = src._energy_point;
		_attack_damage = src._attack_damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap destructor called" << endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name) {
	cout << "ScavTrap constructor param called" << endl;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}

void ScavTrap::guardGate()
{
	cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << endl;
}

void ScavTrap::attack(const string &target)
{
		if (_hit_point <= 0)
	{
		cout << "ScavTrap " << _name << " is dead and cannot attack ! Ohhh... It's Sad !" << endl;
		return;
	}
	if (_energy_point <= 0)
	{
		cout << "ScavTrap " << _name << " does not have enough energy for attack!" << endl;
		return ;
	}
	--_energy_point;
	cout	<< "ScavTrap " << _name << " attack " << target
			<< ", causing " << _attack_damage << " points of damage!" << endl;
}