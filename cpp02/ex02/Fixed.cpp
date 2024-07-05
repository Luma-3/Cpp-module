/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/03 15:44:41 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

// Coplien 

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const Fixed &other) : _value(other._value) {}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other) {
		_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed() {}

// Assignement param

Fixed::Fixed(const int val)
{
	_value = val << _frac_bits;
}
Fixed::Fixed(const float val)
{
	_value = (int)(roundf(val * (1 << _frac_bits)));
}

// Getter / Setter

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(_value) / (1 << _frac_bits));
}

float Fixed::toInt(void) const
{
	return (_value >> _frac_bits);
}

// Operator 

ostream &operator<<(ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const {return (_value > other._value);}

bool Fixed::operator<(const Fixed &other) const {return (_value < other._value);}

bool Fixed::operator>=(const Fixed &other) const {return (_value >= other._value);}

bool Fixed::operator<=(const Fixed &other) const {return (_value <= other._value);}

bool Fixed::operator==(const Fixed &other) const {return (_value == other._value);}

bool Fixed::operator!=(const Fixed &other) const {return (_value != other._value);}

Fixed Fixed::operator+(const Fixed &other) const {
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed& Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

