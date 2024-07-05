/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:39:03 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/05 13:26:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string get_input(std::string &input)
{
	std::getline(std::cin, input);
	if (input.empty() == true)
	{
		std::cout << "le champ ne doit pas etre Vide !" << std::endl;
		return (NULL);
	}
	return (input);
}

int main(void)
{
	std::string	input;
	PhoneBook	book;

	while (true)
	{
		std::cout << "Enter ADD, SEARCH or EXIT !:" << std::endl;
		input = get_input(input);
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
	}
	return (0);
}

