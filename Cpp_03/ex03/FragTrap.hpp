
#pragma once

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& cpy);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& obj);
		void		attack(const	std::string& target);
		void		HighFivesGuys();
};
