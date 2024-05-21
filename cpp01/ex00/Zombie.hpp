/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:39:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/05 00:20:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	void announce(void);

	Zombie(std::string name);
	~Zombie();
};

void randomChump(std::string name);

Zombie *newZombie(std::string name);
