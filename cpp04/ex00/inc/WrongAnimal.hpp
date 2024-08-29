#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal & src);
	WrongAnimal & operator=(const WrongAnimal & src);
	virtual ~WrongAnimal();

	void makeSound(void) const;

	std::string getType(void) const;

};



#endif // WRONGANIMAL_HPP