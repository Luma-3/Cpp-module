/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:05:38 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 19:08:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main()
{
	Array<int> a(5);
	Array<int> b(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i + 10;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	Array<int> c(a);

	std::cout << "c: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	c = b;

	std::cout << "c: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << "c[10]: " << c[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}