/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:14:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:48:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

FragTrap::FragTrap() : ClapTrap() {
	cout << "FragTrap constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src) {
	cout << "FragTrap copy constructor called" << endl;
}

FragTrap & FragTrap::operator=(const FragTrap & src) {
	cout << "FragTrap affectation operator called" << endl;
	if (this != &src) {
		_name = src._name;
		_attack_damage = src._attack_damage;
		_hit_point = src._hit_point;
		_energy_point = src._energy_point;
	}
	return *this;
}

FragTrap::~FragTrap() {
	cout << "FragTrap destructor called" << endl;
}

FragTrap::FragTrap(const string &name) : ClapTrap(name)
{
	cout << "FragTrap constructor param called" << endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

void FragTrap::highFivesGuys(void)
{
	cout << "FragTrap " << _name << " positive high Fives Resquest" << endl;
}