/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:15:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:45:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

using std::cout;
using std::endl;

Cat::Cat() : Animal() {
	cout << "Cat Constructor called" << endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat & src) : Animal(src) {
	cout << "Cat Copy Constructor called" << endl;
	brain = new Brain(*src.brain);
}

Cat & Cat::operator=(const Cat & src) {
	cout << "Cat Affectation opperator called" << endl;
	if (this != &src) {
		type = src.type;
		if (brain)
			delete brain;
		brain = new Brain(*src.brain);
	}
	return *this;
}

Cat::~Cat() {
	cout << "Cat Destructor called" << endl;
	delete brain;
}

void Cat::makeSound(void) const 
{
	cout << "Maow !" << endl;
}