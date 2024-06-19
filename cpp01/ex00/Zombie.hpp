/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:39:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 12:54:20 by jbrousse         ###   ########.fr       */
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

	Zombie(string name);
	~Zombie();

};

void randomChump(string name);

Zombie *newZombie(string name);
