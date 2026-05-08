
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout	<< _name << " constructed (Frag-default)" << std::endl;
	_HitPoint = 100;
	_AttackDmg = 30;
	_EnergyPoint = 100;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoint = 100;
	_AttackDmg = 30;
	std::cout	<< " DEBUG ::::" << _AttackDmg << std::endl;
	_EnergyPoint = 100;
	std::cout	<< _name << " constructed (Frag-by name)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy)
{
	_name  = cpy._name;
	_HitPoint = cpy._HitPoint;
	_AttackDmg = cpy._AttackDmg;
	_EnergyPoint = cpy._EnergyPoint;
	std::cout	<< _name << " constructed (Frag-by copy)" << std::endl;
}

void		FragTrap::attack(const	std::string& target)
{
	if (!(_EnergyPoint > 0 && _HitPoint > 0))
	{
		std::cout	<< "Mr. Subject says : \"Of course, ScavTrap can’t do anything if it has no hit points or energy points left.\"" << std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _AttackDmg << " points of damage!" << std::endl;
	_EnergyPoint -= 1;
}

FragTrap::~FragTrap() {std::cout	<< _name << " destructed (Frag)" << std::endl; }

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_HitPoint = obj._HitPoint;
		_EnergyPoint = obj._EnergyPoint;
		_AttackDmg = obj._AttackDmg;
		std::cout	<< _name << " constructed (by Frag-copy)" << std::endl;
	}
	return (*this);
}

void		FragTrap::HighFivesGuys()
{
	if (_HitPoint <= 0)
		std::cout	<< _name << "... * Nothing happend *" << std::endl;
	else
		std::cout	<< _name << " *ask for high five but Minions refused ...*\n\t" << _name << "\" I must look really stupid right now! \"" << std::endl;
}
