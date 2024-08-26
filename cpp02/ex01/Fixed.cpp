/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/26 09:24:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

Fixed::Fixed(void) : _value(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	cout << "Copy constructor called" << endl;
}

Fixed::Fixed(const int val)
{
	cout << "Int constructor called" << endl;
	_value = val << _frac_bits;
}
Fixed::Fixed(const float val)
{
	cout << "Float Constructor called" << endl;
	_value = (int)(roundf(val * (1 << _frac_bits)));
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

float Fixed::toFloat(void) const
{
	return ((float)(_value) / (1 << _frac_bits));
}

int Fixed::toInt(void) const
{
	return (_value >> _frac_bits);
}

// Operator <<

ostream &operator<<(ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}