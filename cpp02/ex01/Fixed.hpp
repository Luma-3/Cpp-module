/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:35:12 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/03 14:32:34 by jbrousse         ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int val);
	Fixed(const float val);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits (int const raw);
	float toFloat(void) const;
	float toInt(void) const;
};

ostream &operator<<(ostream &out, const Fixed &fixed);

#endif