/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 13:07:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main (void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	
	cout << endl;

	cout << j->getType() << endl;
	cout << i->getType() << endl;
	cout << k->getType() << endl;

	cout << endl;
	
	i->makeSound();
	j->makeSound();
	k->makeSound();

	cout << endl;

	delete j;
	delete i;
	delete k;

	cout << endl;

	Animal* tab[4] = {new Cat, new Cat, new Dog, new Dog};
	cout << endl;
	
	for (int counter = 0; counter < 4; counter++) {
		tab[counter]->makeSound();
		delete tab[counter];
		cout << endl;
	}

	return (0);
}