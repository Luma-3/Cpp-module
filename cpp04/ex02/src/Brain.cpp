/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:35:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/29 12:26:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

using std::cout;
using std::endl;

Brain::Brain() {
	cout << "Brain constructor called" << endl;
}

Brain::Brain(const Brain & src) {
	cout << "Brain copy constructor called" << endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

Brain & Brain::operator=(const Brain & src) {
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	cout << "Brain destructor called" << endl;
}