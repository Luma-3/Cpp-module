/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:15:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:19:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

using std::cout;
using std::endl;

WrongCat::WrongCat() : WrongAnimal() {
	cout << "WrongCat Constructor called" << endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & src) : WrongAnimal(src){
	cout << "WrongCat Copy Constructor called" << endl;
}

WrongCat & WrongCat::operator=(const WrongCat & src) {
	cout << "WrongCat Affectation opperator called" << endl;

	if (this != &src) {
		type = src.type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	cout << "WrongCat Destructor called" << endl;
}

void WrongCat::makeSound(void) const 
{
	cout << "Croa Croa !" << endl;
}