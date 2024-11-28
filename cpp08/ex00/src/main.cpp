/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:43:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/04 10:56:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void) {
	
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);

	try {
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(v, 6) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}