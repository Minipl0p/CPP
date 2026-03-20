
#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	protected:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& cpy);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& obj);
		void		attack(const	std::string& target);
		void		whoAmI();
};
