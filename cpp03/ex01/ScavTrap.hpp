#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	/* data */

public:
	ScavTrap();
	ScavTrap(const ScavTrap & src);
	ScavTrap & operator=(const ScavTrap & src);
	~ScavTrap();

	ScavTrap(const string &name);

	void attack(const string &target);

	void guardGate();
};



#endif // SCAVTRAP_HPP