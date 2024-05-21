/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:33:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/04 22:31:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

std::string Contact::getFirstName(void) {
	return (firstName);
}

std::string Contact::getLastName(void) {
	return (lastName);
}

std::string Contact::getNickname(void) {
	return (nickname);
}

std::string Contact::getPhoneNumber(void) {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret(void) {
	return (darkestSecret);
}

void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;	
}

void Contact::setNickname(const std::string &nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}

Contact::Contact()
{
	firstName = "none";
	lastName = "none";
	nickname = "none";
	phoneNumber = "none";
	darkestSecret = "none";
}