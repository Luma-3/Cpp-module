/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:11:36 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 13:35:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string var = "HI THIS IS BRAIN";
	
	string* stringPTR = &var;
	string& stringREF = var;

	cout << "pointer var: " 				<< &var << endl;
	cout << "Value stringPTR: " 			<< stringPTR << endl;
	cout << "Pointer value of stringREF: "	<< &stringREF << endl;

	cout << "--------------" << endl;

	cout << "value var: " 					<< var << endl;
	cout << "value Pointed by stringPTR: "	<< *stringPTR << endl;
	cout << "value Pointed by stringREF: "	<< stringREF << endl;
}