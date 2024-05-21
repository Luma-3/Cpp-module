/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:10:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/04 20:28:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		std::cout << (char)toupper(str[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		megaphone("* loud and unbearable feedback noise *");
	}
	for (int i = 1; i < argc; i++)
	{
		megaphone(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}