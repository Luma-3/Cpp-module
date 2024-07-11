#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat & src);
	Cat & operator=(const Cat & src);
	~Cat();

	virtual void makeSound(void) const;

};

#endif // CAT_HPP