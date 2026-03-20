#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack() const
{
	if (_weaponB == NULL)
	{
		std::cout	<< _name << " attacks with their empty hands" << std::endl;
		return ;
	}
	std::cout	<< _name << " attacks with their " << _weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {_weaponB = &weapon; };
HumanB::HumanB(Weapon& weapon, const std::string& name) {_weaponB = &weapon; _name = name; };
HumanB::HumanB(const std::string& name) { _weaponB = NULL; _name = name; };
