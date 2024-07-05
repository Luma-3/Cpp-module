/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:35:12 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/03 12:53:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

private:
	int _value;
	const static int _frac_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits (int const raw);
};

#endif