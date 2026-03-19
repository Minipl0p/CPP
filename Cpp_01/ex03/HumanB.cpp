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
