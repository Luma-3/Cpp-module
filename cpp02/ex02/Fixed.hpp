/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:35:12 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/03 15:39:05 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

using std::ostream;

class Fixed
{

private:
	int _value;
	const static int _frac_bits = 8;

public:
	//coplien
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	//assignement param
	Fixed(const int val);
	Fixed(const float val);

	//getter / setter
	int getRawBits(void) const;
	void setRawBits (int const raw);
	float toFloat(void) const;
	float toInt(void) const;

	//operator
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

};

ostream &operator<<(ostream &out, const Fixed &fixed);

#endif