#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack() const
{
	std::cout	<< _name << " attacks with their " << _weaponA->getType() << std::endl;
}
