/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:43:49 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 10:43:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main()
{
	cout << BLUE << "----------------------------------------" << endl;
	cout << "Create a MateriaSource and learn Materia" << endl;
	cout << "----------------------------------------" << RESET << endl << endl;;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	cout << endl << GREEN << "-------------------------" << endl;
	cout << "Create a Character and equip Materia" << endl;
	cout << "-------------------------" << RESET << endl << endl;
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);

	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	// cout << GREEN << "-------------------------" << endl;
	// cout << "Test with a clone Materia" << endl;
	// cout << "-------------------------" << RESET << endl;
	
	// AMateria* clone = tmp2->clone();

	// cout << "Type of the clone : " << clone->getType() << endl;
	
	// delete clone;

	// cout << RED <<"-------------------------" << endl;
	// cout << "End Clone Test" << endl;
	// cout << "-------------------------" << RESET << endl;


	cout << endl << GREEN << "-------------------------" << endl;
	cout << "Use Materia" << endl;
	cout << "-------------------------" << RESET << endl << endl;

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	delete tmp2;

	me->use(1, *bob);

	cout << endl << GREEN << "-------------------------" << endl;
	cout << "Delete all" << endl;
	cout << "-------------------------" << RESET << endl << endl;
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}