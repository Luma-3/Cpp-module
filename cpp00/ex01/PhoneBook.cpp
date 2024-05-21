/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:08:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/04 22:43:17 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <stdlib.h>

PhoneBook::PhoneBook()
{
	index = 0;
	nbContact = 0;
}

void PhoneBook::Add()
{
	Contact contactToAdd;
	std::string input;
	
	std::string fields[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	const size_t nbFields = sizeof(fields) / sizeof(fields[0]);
	
	for (size_t i = 0; i < nbFields;)
	{
		std::cout << fields[i] << ":";
		std::getline(std::cin, input);
		if (input.empty() == true){
			std::cout << "le champ ne doit pas etre Vide !\n";
			continue;
		}
		if (fields[i] == "First Name") {
            contactToAdd.setFirstName(input);
        }
		else if (fields[i] == "Last Name") {
            contactToAdd.setLastName(input);
        }
		else if (fields[i] == "Nickname") {
            contactToAdd.setNickname(input);
        }
		else if (fields[i] == "Phone Number") {
			contactToAdd.setPhoneNumber(input);
		}
		else if (fields[i] == "Darkest Secret") {
            contactToAdd.setDarkestSecret(input);
        }
		i++;
	}
	if (nbContact < 8)
		nbContact++;
	repertory[index] = contactToAdd;
	index++;
	if (index == 8)
		index = 0;
}

void PhoneBook::DisplayRepertory(void)
{
	std::string input;

	std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname\n";
    std::cout << std::string(10, '-') << " | "
              << std::string(10, '-') << " | "
              << std::string(10, '-') << " | "
              << std::string(10, '-') << std::endl;
	for (int i = 0; i < nbContact; i++)
	{
		std::string first_name = repertory[i].getFirstName();
		std::string last_name = repertory[i].getLastName();
		std::string nickname = repertory[i].getNickname();

		std::cout	<< std::right << std::setw(10) << i << " | "
					<< std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << " | "
					<< std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << " | "
					<< std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "\n";
	}
	while (true)
	{
		std::cout << "To see a Contact type its index: ";
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && atoi(input.c_str()) < nbContact)
		{
			int index = input[0] - '0';
			std::cout << "First Name: " << repertory[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << repertory[index].getLastName() << std::endl;
			std::cout << "Nickname: " << repertory[index].getNickname() << std::endl;
			std::cout << "Phone Number: " << repertory[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << repertory[index].getDarkestSecret() << std::endl;
			break;
		}
		else
			std::cout << "Invalid index\n";
	}
}
