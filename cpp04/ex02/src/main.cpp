/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 13:34:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main (void)
{

	cout << GREEN << "Dog and Cat class Test :" << endl;
	cout << "-------------------------" << RESET << endl;
	
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

	cout << GREEN << "-------------------------" << endl;
	cout << "Test with an array of Animal class" << endl;
	cout << "-------------------------" << RESET << endl << endl;

	Animal* tab[4] = {new Cat, new Cat, new Dog, new Dog};
	cout << endl;
	
	for (int counter = 0; counter < 4; counter++) {
		tab[counter]->makeSound();
		delete tab[counter];
		cout << endl;
	}

	cout << RED << "-------------------------" << endl;
	cout << "End of the test" << RESET << endl;

	return (0);
}