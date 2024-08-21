/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:16 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:56:31 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

using std::string;

Character::Character() : _name("unknown")
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}


Character::Character(const Character &src) : _name(src._name)
{
	for (size_t i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = src.inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		_name = src._name;
		for (size_t i = 0; i < 4; i++)
		{
			delete inventory[i];
		}
		for (size_t i = 0; i < 4; i++)
		{
			inventory[i] = src.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
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
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	// TODO Chain list ?
	if (inventory[idx] != NULL)
	{
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
}