#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
private:
	/* data */

public:
	Ice();
	Ice(const Ice & src);
	Ice & operator=(const Ice & src);
	~Ice();

};

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice & src) : AMateria(src) {}

Ice & Ice::operator=(const Ice & src) {
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

Ice::~Ice() {

}

#endif // ICE_HPP