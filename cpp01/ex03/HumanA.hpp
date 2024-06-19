/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:06:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:19:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp" // Add this line

#include <iostream>

using std::cout;
using std::endl;

class HumanA
{
private:
	string name;
	Weapon &weapon;

public:
	HumanA(string name, Weapon &weapon);
	~HumanA();

	void attack();
};

#endif

