/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:57 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/02 16:42:33 by jbrousse         ###   ########.fr       */
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
	cout << endl << "[DEBUG]" << endl << endl;

	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << endl;
}

void Harl::info(void)
{
	cout << endl << "[INFO]" << endl << endl;

	cout << "I cannot believe adding extra bacon costs more money.\n\
	You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
}

void Harl::warning(void)
{
	cout << endl <<  "[WARNING]" << endl << endl;

	cout << "I think I deserve to have some extra bacon for free. I’ve been coming\
for years whereas you started working here since last month." << endl;
}

void Harl::error(void)
{
	cout << endl << "[ERROR]" << endl << endl;

	cout << "This is unacceptable ! I want to speak to the manager now." << endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == _complains[i].level) {
			switch (i)
			{
			case 0:
				(this->*_complains[0].function)();
				(this->*_complains[1].function)();
				(this->*_complains[2].function)();
				(this->*_complains[3].function)();
				break;
			case 1:
				(this->*_complains[1].function)();
				(this->*_complains[2].function)();
				(this->*_complains[3].function)();
				break;
			case 2:
				(this->*_complains[2].function)();
				(this->*_complains[3].function)();
				break;
			case 3:
				(this->*_complains[3].function)();
				break;
			
			default:
				break;
			}
			return;
		}
	}
	cout << "Unknow level: " << level << endl;
}

