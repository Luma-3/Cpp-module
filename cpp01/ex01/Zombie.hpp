/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:39:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 13:03:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::string;

class Zombie
{
private:
	string _name;

public:
	void announce(void);

	Zombie();
	Zombie(string name);
	~Zombie();
	
	void setName(string name);
};

void randomChump(string name);

Zombie *newZombie(string name);

Zombie	*zombieHorde(int N, string name);
