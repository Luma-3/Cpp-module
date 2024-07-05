/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:39:03 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/05 16:09:05 by jbrousse         ###   ########.fr       */
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
		std::cout << "Enter ADD, SEARCH or EXIT !:" << std::endl;
		std::getline(std::cin, input);

		if (std::cin.eof())
			break ;
		if (input == "ADD")
		{
			book.Add();
		}
		else if ((input) == "SEARCH")
		{
			book.DisplayRepertory();
		}
		else if (input == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Command not found" << std::endl;
		}
	}
	return (0);
}

