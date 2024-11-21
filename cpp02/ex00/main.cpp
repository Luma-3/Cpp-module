/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:00:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/22 12:51:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;

	a.setRawBits(34);

	cout << a.getRawBits() << endl;
	
	return 0;
}