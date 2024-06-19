/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:02:43 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:23:23 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HumanB
{
private:
	Weapon *weapon;
	string name;

public:
	HumanB(string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);
	
};


#endif