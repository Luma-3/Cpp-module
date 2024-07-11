/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:16 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 17:29:19 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("unknown")
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character &src) : name(src.name)
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
		name = src.name;
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
	return name;
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter &target)
{
}