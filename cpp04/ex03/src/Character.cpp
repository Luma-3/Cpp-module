/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:16 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 12:27:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#define MAX_INVENTORY 4

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Character::Character() : _name("unknown")
{
	cout << GREEN << "Character created by Default constructor" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	cout << GREEN << "Character created by Param constructor" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		inventory[i] = NULL;
	}
}


Character::Character(const Character &src) : _name(src._name)
{
	cout << GREEN << "Character created by Copy constructor" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		delete inventory[i];
		inventory[i] = src.inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &src)
{
	cout << YELLOW << "Character created by Assignation operator" << RESET << endl;
	if (this != &src)
	{
		_name = src._name;
		for (size_t i = 0; i < MAX_INVENTORY; i++)
		{
			delete inventory[i];
			inventory[i] = src.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	cout << RED << "Character destroyed" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		delete inventory[i];
	}
}

string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			cout << "Materia: " << m->getType() << " equipped at: " << i << endl;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (inventory[idx] != NULL)
	{
		cout << "Materia: " << inventory[idx]->getType() << " unequipped at: " << idx << endl;
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
}