/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:16:24 by luma              #+#    #+#             */
/*   Updated: 2024/08/04 18:19:40 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int ac, char **av) {
	if (ac != 2) {
		cout << "Incorect numbre of argument" << endl;
		return (1);
	}
	
	ScalarConverter::convert(string(av[1]));
	return (0);
}