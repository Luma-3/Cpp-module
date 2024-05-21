/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:19:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/05 00:39:11 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name[] = {"Albert", "Jinette", "Jean-Claude", "Berte", "Bernard", "Arnulf"};
	Zombie *tab[5];
	
	std::cout << "heap horde:" << std::endl;
	for (size_t i = 0; i < 6; i++)
	{
		tab[i] = newZombie(name[i]);
		tab[i]->announce();
	}

	for (size_t i = 0; i < 6; i++)
	{
		delete tab[i];
	}
	
	
	std::cout << "stack horde:" << std::endl;
	for (size_t i = 0; i < 6; i++)
	{
		randomChump(name[i]);
	}
	return 0;
}
