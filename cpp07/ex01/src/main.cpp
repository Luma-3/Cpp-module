/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:53:09 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 18:55:11 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main(void)
{
	int			intArray[] = {1, 2, 3, 4, 5};
	float		floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	iter(intArray, 5, print);
	iter(floatArray, 5, print);
	iter(stringArray, 5, print);

	return 0;
}