/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:36:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/03 12:30:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

using std::endl;
using std::cout;

Base *generate(void) {
	srand(time(NULL));
	int rand = std::rand() % 3;
	switch (rand)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2: 
		return (new C);
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		cout << "A" << endl;
	}
	else if (dynamic_cast<B*>(p)) {
		cout << "B" << endl;
	}
	else if (dynamic_cast<C*>(p)) {
		cout << "C" << endl;
	}
	else
		cout << "unknown" << endl;
}

void identify(Base &p) {
	try
	{
		A& a = dynamic_cast<A&>(p);
		cout << "A" << endl;
		(void)a;
	}
	catch(...) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		cout << "B" << endl;
		(void)b;
	}
	catch(...) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		cout << "C" << endl;
		(void)c;
	}
	catch(...) {}
}

int main() {

	Base *rand = generate();
	
	cout << "Pointer: ";
	identify(rand);
	cout << "Referance: ";
	identify(*rand);
	delete rand;
	return(0);
}