/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:27:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 10:34:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

using std::cout;
using std::endl;

#define MAX_INVENTORY 4

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

MateriaSource::MateriaSource() {
	cout << GREEN <<"MateriaSource created by Default constructor" <<RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource & src) {
	cout << GREEN << "MateriaSource created by Copy constructor" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		delete inventory[i];
		inventory[i] = src.inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src) {
	cout << YELLOW <<"MateriaSource created by Assignation operator" << RESET << endl;
	if (this != &src) {
		for (size_t i = 0; i < MAX_INVENTORY; i++)
		{
			delete inventory[i];
			inventory[i] = src.inventory[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	cout << RED << "MateriaSource destroyed" << RESET << endl;
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		delete inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			cout << "Materia: " << m->getType() << " learned at: " << i << endl;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < MAX_INVENTORY; i++)
	{
		if ( inventory[i] && inventory[i]->getType() == type)
		{
			cout << "Materia: " << type << " created at: " << i << endl;
			return inventory[i]->clone();
		}
	}
	return (NULL);
}