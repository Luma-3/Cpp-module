#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal & src);
	Animal & operator=(const Animal & src);
	virtual ~Animal();

	virtual void makeSound(void) const = 0;

	std::string getType(void) const;

};



#endif // ANIMAL_HPP