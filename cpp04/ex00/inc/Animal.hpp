#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

using std::string;

class Animal {
protected:
	string type;

public:
	Animal();
	Animal(const Animal & src);
	Animal & operator=(const Animal & src);
	virtual ~Animal();

	virtual void makeSound(void) const;

	string getType(void) const;

};



#endif // ANIMAL_HPP