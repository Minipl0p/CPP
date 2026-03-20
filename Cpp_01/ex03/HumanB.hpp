#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon	*_weaponB;
	public:
		HumanB(Weapon& weapon, const std::string& name);
		HumanB(const std::string& name);
		~HumanB() {};

		void	attack() const;
		void	setWeapon(Weapon& weapon);
};

#endif
