/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:15:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:58:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

using std::cout;
using std::endl;

Dog::Dog() : Animal() {
	cout << "Dog Constructor called" << endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog & src) : Animal(src){
	cout << "Dog Copy Constructor called" << endl;
	brain = new Brain (*src.brain);
}

Dog & Dog::operator=(const Dog & src) {
	cout << "Dog Affectation opperator called" << endl;
	if (this != &src) {
		type = src.type;
		if (brain)
			delete brain;
		brain = new Brain(*src.brain);
	}
	return *this;
}

Dog::~Dog() {
	cout << "Dog Destructor called" << endl;
	delete brain;
}

void Dog::makeSound(void) const 
{
	cout << "Woof, Woof !" << endl;
}