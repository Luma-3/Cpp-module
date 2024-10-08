/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 12:24:08 by jbrousse         ###   ########.fr       */
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
	const WrongCat* l = new WrongCat();
	
	cout << endl;

	cout << j->getType() << endl;
	cout << i->getType() << endl;
	cout << k->getType() << endl;

	cout << endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	k->makeSound();
	l->makeSound();
	

	cout << endl;

	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;

	return (0);
}