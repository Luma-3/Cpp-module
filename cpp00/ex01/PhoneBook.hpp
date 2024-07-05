/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:14:57 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/05 16:08:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
private:
	int index;
	int nbContact;
	Contact repertory[8];

public:
	PhoneBook(void);

	void	Add(void);
	void	DisplayRepertory(void);
};

#endif