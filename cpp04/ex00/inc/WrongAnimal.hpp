#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

using std::string;

class WrongAnimal {
protected:
	string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal & src);
	WrongAnimal & operator=(const WrongAnimal & src);
	virtual ~WrongAnimal();

	virtual void makeSound(void) const;

	string getType(void) const;

};



#endif // WRONGANIMAL_HPP