#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap & src);
	DiamondTrap & operator=(const DiamondTrap & src);
	~DiamondTrap();

	DiamondTrap(const std::string &name);

	void whoAmI(void);
};



#endif // DIAMONDTRAP_HPP