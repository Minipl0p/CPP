#ifndef HUMMANA_HPP
# define HUMMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon	*_weaponA;
	public:
		HumanA(const std::string& name, Weapon& weapon) {_weaponA = &weapon; _name = name; };
		~HumanA() {};

		void	attack() const;
};
#endif
