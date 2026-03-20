
#pragma once

#include <string>

class	ClapTrap
{
	protected:
	std::string	_name;
	size_t		_HitPoint;
	size_t		_EnergyPoint;
	size_t		_AttackDmg;
	public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& cpy);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& obj);
	void		attack(const	std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
