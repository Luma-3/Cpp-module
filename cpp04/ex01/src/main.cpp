/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:59:53 by jbrousse         ###   ########.fr       */
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
	const Animal* meta = new Animal();
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
	meta->makeSound();
	k->makeSound();

	cout << endl;

	delete meta;
	delete j;
	delete i;
	delete k;

	cout << endl;

	Animal* tab[4] = {new Cat, new Cat, new Dog, new Dog};

	for (int i = 0; i < 4; i++) {
		tab[i]->makeSound();
		delete tab[i];
	}

	return (0);
}