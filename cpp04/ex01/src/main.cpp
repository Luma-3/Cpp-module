/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/28 13:20:03 by jbrousse         ###   ########.fr       */
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
	Animal* tab[4] = {new Cat, new Cat, new Dog, new Dog};

	for (int i = 0; i < 4; i++) {
		tab[i]->makeSound();
		delete tab[i];
	}

	return (0);
}