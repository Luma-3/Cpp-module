/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:33:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 10:38:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap() : _name("none"), _hit_point(10), _energy_point(10), _attack_damage(0) {
	cout << "ClapTrap constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap & src) :
	_name(src._name),
	_hit_point(src._hit_point),
	_energy_point(src._energy_point),
	_attack_damage(src._attack_damage)
{
	cout << "ClapTrap copy constructor called" << endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & src) {
	cout << "ClapTrap affectation operator called" << endl;
	if (this != &src) {
		_hit_point = src._hit_point;
		_energy_point = src._energy_point;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap destructor called" << endl;
}

ClapTrap::ClapTrap(const string &name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0) {
	cout << "ClapTrap constructor param called" << endl;
}

void	ClapTrap::attack(const string &target)
{
	if (_hit_point == 0)
	{
		cout << "ClapTrap " << _name << " is dead and cannot attack ! Ohhh... It's Sad !" << endl;
		return;
	}
	if (_energy_point == 0)
	{
		cout << "ClapTrap " << _name << " does not have enough energy for attack!" << endl;
		return ;
	}
	--_energy_point;
	cout	<< "ClapTrap " << _name << " attack " << target
			<< ", causing " << _attack_damage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point == 0)
	{
		cout << "ClapTrap is already dead!" << endl;
		return;
	}
	_hit_point = (_hit_point > amount) ? _hit_point - amount : 0;
	cout << "ClapTrap " << _name << " took " << amount << " Damage point ! Ooouf!" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_point <= 0)
	{
		cout << "ClapTrap " << _name << " does not have enough energy to repair itself." << endl;
		return;

	}
	if (_hit_point <= 0)
	{
		cout << "ClapTrap " << _name << " is already dead!" << endl;
		return;

	}
	_hit_point += amount;
	--_energy_point;
	cout << "ClapTrap " << _name << " has been repaired by " << amount << " points!" << endl;
}


const string &ClapTrap::getName(void) const
{
	return _name;
}

unsigned int ClapTrap::getHitPoint(void) const
{
	return _hit_point;
}

unsigned int ClapTrap::getEnergyPoint(void) const
{
	return _energy_point;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return _attack_damage;
}
