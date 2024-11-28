/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:30:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/03 14:56:23 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>
#include <iostream>

void add_one(int &i) {
	i++;
}

void rot_one(char &c) {
	c--;
}

void print_int(int i) {
	std::cout << i << std::endl;
}

void print_char(char c) {
	std::cout << c;
}

int main(void) {
	int arr_i[5] = {1, 2, 3, 4, 5};
	iter(arr_i, 5, print_int);
	std::cout << std::endl;
	iter(arr_i, 5, add_one);
	iter(arr_i, 5, print_int);
	std::cout << std::endl;

	char arr_c[13] = "Hello, World";
	iter(arr_c, 12, print_char);
	std::cout << std::endl;
	iter(arr_c, 12, rot_one);
	iter(arr_c, 12, print_char);
	std::cout << std::endl;
	return (0);
}