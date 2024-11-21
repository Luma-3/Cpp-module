/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:00:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/26 09:38:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"



int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	
	a < b ? std::cout << "a is minus than b" << std::endl : std::cout << "a is greater than b" << std::endl;
	a > b ? std::cout << "a is greater than b" << std::endl : std::cout << "a is minus than b" << std::endl;
	a <= b ? std::cout << "a is minus or equal to b" << std::endl : std::cout << "a is greater than b" << std::endl;
	a >= b ? std::cout << "a is greater or equal to b" << std::endl : std::cout << "a is minus than b" << std::endl;
	a == b ? std::cout << "a is equal to b" << std::endl : std::cout << "a is not equal to b" << std::endl;
	a != b ? std::cout << "a is not equal to b" << std::endl : std::cout << "a is equal to b" << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed c(42.42f);
	std::cout << c + b << std::endl;
	std::cout << c - b << std::endl;
	std::cout << c * b << std::endl;
	std::cout << c / b << std::endl;
	
	return 0;
}