/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:09:01 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:55:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

WrongAnimal::WrongAnimal() : type("none"){
	cout << "WrongAnimal Constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src) : type(src.type) {
	cout << "WrongAnimal Copy Constructor called" << endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src) {
	cout << "WrongAnimal Affectation opperator called" << endl;
	if (this != &src) {
		type = src.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal Destructor called" << endl;
}

void WrongAnimal::makeSound(void) const 
{
	cout << "WrongAnimal make Sound !" << endl;
}

string WrongAnimal::getType(void) const
{
	return (type);
}
