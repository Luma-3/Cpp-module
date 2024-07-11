#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::string;

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	string _name;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap & src);
	DiamondTrap & operator=(const DiamondTrap & src);
	~DiamondTrap();

	DiamondTrap(const string &name);

	void whoAmI(void);
};



#endif // DIAMONDTRAP_HPP