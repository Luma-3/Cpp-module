/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:57 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/02 13:32:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using std::cout;
using std::endl;

Harl::Harl() {
	_complains[0].level = "DEBUG";
	_complains[0].function =  &Harl::debug;
	_complains[1].level  =	"INFO";
	_complains[1].function = &Harl::info;
	_complains[2].level  =	"WARNING";
	_complains[2].function = &Harl::warning;
	_complains[3].level  = "ERROR";
	_complains[3].function =  &Harl::error;
}

void Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming\
for years whereas you started working here since last month." << endl;
}

void Harl::error(void)
{
	cout << "This is unacceptable ! I want to speak to the manager now." << endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == _complains[i].level) {
			(this->*_complains[i].function)();
			return;
		}
	}
	cout << "Unknow level: " << level << endl;
}

