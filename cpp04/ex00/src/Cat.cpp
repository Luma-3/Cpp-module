/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:15:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:18:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

using std::cout;
using std::endl;

Cat::Cat() : Animal() {
	cout << "Cat Constructor called" << endl;
	type = "Cat";
}

Cat::Cat(const Cat & src) : Animal(src) {
	cout << "Cat Copy Constructor called" << endl;
}

Cat & Cat::operator=(const Cat & src) {
	cout << "Cat Affectation opperator called" << endl;
	if (this != &src) {
		type = src.type;
	}
	return *this;
}

Cat::~Cat() {
	cout << "Cat Destructor called" << endl;
}

void Cat::makeSound(void) const 
{
	cout << "Maow !" << endl;
}