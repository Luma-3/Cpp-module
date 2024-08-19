/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:39:13 by luma              #+#    #+#             */
/*   Updated: 2024/08/05 18:51:30 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Data data = {"Michelle", 52};

	cout << "Send Data:" << endl;
	cout << data.name << endl;
	cout << data.age << endl;

	uintptr_t ptr = Serializer::serialize(&data);

	Data *other = Serializer::deserialize(ptr);


	cout << "Recieve Data :" << endl;
	cout << other->name << endl;
	cout << other->age << endl;
	
	return 0;
}
