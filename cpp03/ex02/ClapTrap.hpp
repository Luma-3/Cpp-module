#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
	const std::string	_name;
	unsigned int		_hit_point;
	unsigned int		_energy_point;
	unsigned int		_attack_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap & src);
	ClapTrap & operator=(const ClapTrap & src);
	~ClapTrap();

	ClapTrap(const std::string &name);

	virtual void	attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string	&getName(void) const;
	unsigned int		getHitPoint(void) const;
	unsigned int		getEnergyPoint(void) const;
	unsigned int		getAttackDamage(void) const;

};

#endif // CLAPTRAP_HPP