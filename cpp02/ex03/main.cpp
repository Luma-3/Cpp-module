/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:00:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/08 13:53:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int main( void ) {
	
	Point a(0, 0);
	Point b(0, 4);
	Point c(4, 0);

	Point p1(1.5, 0.1);

	bsp(a, b, c, p1) ? std::cout << "p1 is inside the triangle abc" << std::endl : std::cout << "p1 is outside the triangle abc" << std::endl;
	
	return 0;
}