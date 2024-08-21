#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
	std::string _name;
	int	_hit_point;
	int _energy_point;
	int _attack_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap & src);
	ClapTrap & operator=(const ClapTrap & src);
	~ClapTrap();

	ClapTrap(const std::string &name);
	ClapTrap(const std::string &name, unsigned int hit_point, unsigned int energy_point, unsigned int attack_damage);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(const std::string &name);
	void setHitPoint(unsigned int hit_point);
	void setEnergyPoint(unsigned int energy_point);
	void setAttackDamage(unsigned int attack_damage);

	std::string getName(void) const;
	unsigned int getHitPoint(void) const;
	unsigned int getEnergyPoint(void) const;
	unsigned int getAttackDamage(void) const;

};

#endif // CLAPTRAP_HPP