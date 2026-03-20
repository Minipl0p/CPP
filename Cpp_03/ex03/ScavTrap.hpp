
#pragma once

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& cpy);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& obj);
		void		attack(const	std::string& target);
		void		GuardGate();
};
