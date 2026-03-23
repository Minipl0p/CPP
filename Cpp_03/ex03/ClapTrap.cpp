
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Clappy"), _HitPoint(10), _EnergyPoint(10), _AttackDmg(0) {
	std::cout	<< _name << " constructed (default)" << std::endl; }

ClapTrap::ClapTrap(const std::string& name) : _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDmg(0) {
	std::cout	<< _name << " constructed (by name)" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& cpy) : _name(cpy._name), _HitPoint(10), _EnergyPoint(10), _AttackDmg(0) {
	std::cout	<< _name << " constructed (by copy)" << std::endl; }

ClapTrap::~ClapTrap() { std::cout	<< _name << " destructed\n" << std::flush; }

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	if (this == &obj)
		return (*this);
	_name = obj._name;
	_HitPoint = 10;
	_EnergyPoint = 10;
	_AttackDmg = 0;
	std::cout	<< _name << " constructed (by copy)" << std::endl;
	return (*this);
}

void		ClapTrap::attack(const	std::string& target)
{
	if (!(_EnergyPoint > 0 && _HitPoint > 0))
	{
		std::cout	<< "Mr. Subject says : \"Of course, ClapTrap can’t do anything if it has no hit points or energy points left.\"" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _AttackDmg << " points of damage!" << std::endl;
	_EnergyPoint -= 1;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoint <= 0)
	{
		std::cout	<< "Minions ! You can't kill someone who's already dead !" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << _name << " take " << amount << " damage " << std::endl;
	amount >= _HitPoint ? _HitPoint = 0 : _HitPoint -= amount;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoint <= 0)
	{
		std::cout	<< "*BzzZz BzZz* \" Ca .n  n oooot mo mo.mov e\"" << std::endl;
		return ;
	}
	if (_HitPoint <= 0)
	{
		std::cout	<< "... * Nothing happend *" << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << _name << " is repairing himself for " << amount << "hp" << std::endl;
	_EnergyPoint -= 1;
	amount >= 10 ? _HitPoint = 10 : _HitPoint += amount;
}
