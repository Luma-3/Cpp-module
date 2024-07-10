#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

using std::string;

class ClapTrap {
protected:
	string _name;
	int	_hit_point;
	int _energy_point;
	int _attack_damage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap & src);
	ClapTrap & operator=(const ClapTrap & src);
	~ClapTrap();

	ClapTrap(const string &name);

	virtual void attack(const string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(const string &name);
	void setHitPoint(unsigned int hit_point);
	void setEnergyPoint(unsigned int energy_point);
	void setAttackDamage(unsigned int attack_damage);

	string getName(void) const;
	unsigned int getHitPoint(void) const;
	unsigned int getEnergyPoint(void) const;
	unsigned int getAttackDamage(void) const;

};

#endif // CLAPTRAP_HPP