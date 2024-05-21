/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:39:03 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/04 22:11:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string	input;
	PhoneBook	book;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			book.Add();
		}
		else if (input == "SEARCH")
		{
			book.DisplayRepertory();
		}
		else if (input == "EXIT")
		{
			break;
		}
	}
	return (0);
}

