/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:58:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/02 11:38:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

using std::string;
using std::cout;

void usage()
{
	cout << "Usage: ./sed <file_name> <occurance> <replace>\n";
}

int main(int ac, char **av)
{
	if (ac <= 1 || ac > 4) {
		usage();
		return (1);
	}
	return (copy_file(string(av[1]), av[2], av[3]));
}