/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:27:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 18:41:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource & src) {
	for (size_t i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = src.inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src) {
	if (this != &src) {
		for (size_t i = 0; i < 4; i++)
		{
			delete inventory[i];
		}
		for (size_t i = 0; i < 4; i++)
		{
			inventory[i] = src.inventory[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if ( inventory[i] && inventory[i]->getType() == type)
		{
			return inventory[i]->clone();
		}
	}
	return (NULL);
}