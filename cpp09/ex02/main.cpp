/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/03 16:35:52 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <cstdlib>
#include <cstring>
#include <iostream>

#include "PmergeMe.hpp"

static void verifInput(int ac, char **av)
{
	size_t j = 0;

	for (int i = 0; i < ac; ++i) {
		j = 0;
		while (av[i][j] != 0) {
			if (isdigit(av[i][j]) == 0) {
				throw std::runtime_error("Invalide Input: " +
										 std::string(av[i]));
			}
			++j;
		}
	}
}

static int *createTab(int ac, char **av)
{
	int *tab = new int[ac];

	for (int i = 0; i < ac; ++i) {
		tab[i] = atoi(av[i]);
	}
	return tab;
}

int *parse(int ac, char **av)
{
	int *tab = NULL;
	verifInput(ac, av);

	tab = createTab(ac, av);

	for (int i = 0; i < ac - 1; ++i) {
		for (int j = i + 1; j < ac; ++j) {
			if (tab[i] < 0 || tab[j] < 0) {
				delete[] tab;
				throw std::runtime_error(
					"Invalid Input: Negative number overflow");
			}

			if (tab[i] == tab[j]) {
				delete[] tab;
				throw std::runtime_error("Invalid Input: Duplicate number " +
										 to_string(tab[i]));
			}
		}
	}

	return tab;
}

int main(int ac, char **av)
{
	int *tab = NULL;

	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << " <number>" << std::endl;
		return 1;
	}

	try {
		tab = parse(ac - 1, av + 1);
		PmergeMe merger(tab, ac - 1);
		merger.mergeSortVector();
	} catch (std::exception &e) {
		delete[] tab;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	delete[] tab;

	return 0;
}