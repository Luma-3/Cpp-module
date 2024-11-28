/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:04:38 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/04 10:13:17 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <Array.hpp>

int main(void) {
	Array<int> a(12);
	
	for (unsigned int i = 0; i < 12; ++i) {
		a[i] = i + 1;

		std::cout << a[i] << std::endl;
	}

	a[13];
}