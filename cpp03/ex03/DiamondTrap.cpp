/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:58:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/10 17:11:27 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {

}

DiamondTrap::DiamondTrap(const DiamondTrap & src) {

}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & src) {
	if (this != &src) {
		;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {

}

DiamondTrap::DiamondTrap(const string &name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	cout << "DiamoundTrap param contructor called" <<endl;
}