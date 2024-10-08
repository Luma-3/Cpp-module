#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
	/* data */

public:
	FragTrap();
	FragTrap(const FragTrap & src);
	FragTrap & operator=(const FragTrap & src);
	~FragTrap();

	FragTrap(const std::string &name);

	void highFivesGuys(void);
};



#endif // FRAGTRAP_HPP