
#pragma once

#include <string>

class	ClapTrap
{
	private:
	std::string	name;
	size_t		HitPoint;
	size_t		EnergyPoint;
	size_t		AttackDmg;
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cpy);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& obj);
	void		attack(const	std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
