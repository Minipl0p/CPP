
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	std::cout	<< _name << " constructed (Diam-default)" << std::endl;
	_name = "Default";
	_HitPoint = FragTrap::_HitPoint;
	_AttackDmg = FragTrap::_AttackDmg;
	_EnergyPoint = ScavTrap::_EnergyPoint;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout	<< _name << " constructed (Diam-by name)" << std::endl;
	_name = name;
	_HitPoint = FragTrap::_HitPoint;
	_AttackDmg = FragTrap::_AttackDmg;
	_EnergyPoint = ScavTrap::_EnergyPoint;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpy) : ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy)
{
	std::cout	<< _name << " constructed (Diam-by copy)" << std::endl;
	_name  = cpy._name;
	_HitPoint = cpy._HitPoint;
	_AttackDmg = cpy._AttackDmg;
	_EnergyPoint = cpy._EnergyPoint;
}

void		DiamondTrap::attack(const	std::string& target) { ScavTrap::attack(target); }

DiamondTrap::~DiamondTrap() {std::cout	<< _name << " destructed (Diam)" << std::endl; }

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this == &obj)
		return (*this);
	_name = obj._name;
	_HitPoint = obj._HitPoint;
	_EnergyPoint = obj._EnergyPoint;
	_AttackDmg = obj._AttackDmg;
	std::cout	<< _name << " constructed (by Diam-copy)" << std::endl;
	return (*this);
}

void		DiamondTrap::whoAmI()
{
	if (this->_HitPoint > 0)
		std::cout	<< "Clap_name is : " << ClapTrap::_name
					<< "\nDiamond_name is : " << _name << std::endl;
	else
		std::cout	<< "... *Nothing happens*\n" << std::flush;
}
