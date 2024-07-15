#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

#include "ICharacter.hpp"

#include <iostream>

using std::cout;
using std::endl;

class Cure : public AMateria {

public:
	Cure();
	Cure(const Cure & src);
	Cure & operator=(const Cure & src);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif // CURE_HPP