/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:09:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:51:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

Animal::Animal() : type("none"){
	cout << "Animal Constructor called" << endl;
}

Animal::Animal(const Animal & src) : type(src.type) {
	cout << "Animal Copy Constructor called" << endl;
}

Animal & Animal::operator=(const Animal & src) {
	cout << "Animal Affectation opperator called" << endl;
	if (this != &src) {
		type = src.type;
	}
	return *this;
}

Animal::~Animal() {
	cout << "Animal Destructor called" << endl;
}

void Animal::makeSound(void) const 
{
	cout << "Animal make Sound !" << endl;
}

string Animal::getType(void) const {
	return (type);
}