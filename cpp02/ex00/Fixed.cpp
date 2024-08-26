/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/22 10:20:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

using std::cout;
using std::endl;

Fixed::Fixed(void) : _value(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	cout << "Copy constructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	_value = raw;
}