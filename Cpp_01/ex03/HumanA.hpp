#ifndef HUMMANA_HPP
# define HUMMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon	*_weaponA;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA() {};

		void	attack() const;
};
#endif
