/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:08:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/05 10:59:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <stdlib.h>

using std::string;
using std::setw;

using std::cout;
using std::cin;
using std::endl;

PhoneBook::PhoneBook()
{
	index = 0;
	nbContact = 0;
}

void PhoneBook::Add()
{
	Contact contactToAdd;
	string input;
	
	string fields[] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	const size_t nbFields = sizeof(fields) / sizeof(fields[0]);

	size_t i = 0;
	while (i < nbFields)
	{
		cout << fields[i] << ":";
		std::getline(cin, input);
		if (input.empty() == true){
			cout << "le champ ne doit pas etre Vide !\n";
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
		++i;
	}
	if (nbContact < 8)
		nbContact++;
	repertory[index] = contactToAdd;
	index++;
	if (index == 8)
		index = 0;
}

static string trunc_str_if(string &arg)
{
	if (arg.length() > 10)
	{
		return (arg.substr(0, 9) + ".");
	}
	return (arg);
}

void PhoneBook::DisplayRepertory(void)
{
	string input;

	cout << setw(10) << "Index" << " | "
              << setw(10) << "First Name" << " | "
              << setw(10) << "Last Name" << " | "
              << setw(10) << "Nickname\n";
    cout << string(10, '-') << " | "
              << string(10, '-') << " | "
              << string(10, '-') << " | "
              << string(10, '-') << endl;
	for (int i = 0; i < nbContact; i++)
	{
		string first_name = repertory[i].getFirstName();
		string last_name = repertory[i].getLastName();
		string nickname = repertory[i].getNickname();

		cout	<< std::right << setw(10) << i << " | "
					<< setw(10) << trunc_str_if(first_name) << " | "
					<< setw(10) << trunc_str_if(last_name) << " | "
					<< setw(10) << trunc_str_if(nickname) << "\n";
	}
	while (true)
	{
		cout << "To see a Contact type its index: ";
		std::getline(cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && atoi(input.c_str()) < nbContact)
		{
			int index = input[0] - '0';
			cout << "First Name: " << repertory[index].getFirstName() << endl;
			cout << "Last Name: " << repertory[index].getLastName() << endl;
			cout << "Nickname: " << repertory[index].getNickname() << endl;
			cout << "Phone Number: " << repertory[index].getPhoneNumber() << endl;
			cout << "Darkest Secret: " << repertory[index].getDarkestSecret() << endl;
			break;
		}
		else
			cout << "Invalid index\n";
	}
}
