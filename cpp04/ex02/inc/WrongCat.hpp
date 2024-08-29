#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
private:

public:
	WrongCat();
	WrongCat(const WrongCat & src);
	WrongCat & operator=(const WrongCat & src);
	~WrongCat();

	void makeSound(void) const;

};

#endif // WRONGCAT_HPP