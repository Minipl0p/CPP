
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout	<< _name << " constructed (Scav-default)" << std::endl;
	_HitPoint = 100;
	_AttackDmg = 20;
	_EnergyPoint = 50;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoint = 100;
	_AttackDmg = 20;
	_EnergyPoint = 50;
	std::cout	<< _name << " constructed (Scav-by name)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy)
{
	_name  = cpy._name;
	_HitPoint = cpy._HitPoint;
	_AttackDmg = cpy._AttackDmg;
	_EnergyPoint = cpy._EnergyPoint;
	std::cout	<< _name << " constructed (Scav-by copy)" << std::endl;
}

void		ScavTrap::attack(const	std::string& target)
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

ScavTrap::~ScavTrap() {std::cout	<< _name << " destructed (Scav)" << std::endl; }

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	_name = obj._name;
	_HitPoint = obj._HitPoint;
	_EnergyPoint = obj._EnergyPoint;
	_AttackDmg = obj._AttackDmg;
	std::cout	<< _name << " constructed (by Scav-copy)" << std::endl;
	return (*this);
}

void		ScavTrap::GuardGate()
{
	if (_HitPoint <= 0)
		std::cout	<< _name << "... * Nothing happend *" << std::endl;
	else
		std::cout	<< _name << " is now in guarding stance" << std::endl;
}
