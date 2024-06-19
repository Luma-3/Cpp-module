/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:19:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 13:07:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using std::cout;

int main(void)
{
	
	Zombie *zombies = zombieHorde(5, "Arnulf");

	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	
	return 0;
}
