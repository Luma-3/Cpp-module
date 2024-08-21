#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
private:
	/* data */

public:
	ScavTrap();
	ScavTrap(const ScavTrap & src);
	ScavTrap & operator=(const ScavTrap & src);
	~ScavTrap();

	ScavTrap(const std::string &name);

	void attack(const std::string &target);

	void guardGate();
};



#endif // SCAVTRAP_HPP