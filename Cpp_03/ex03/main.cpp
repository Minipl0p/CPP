
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main (void)
{
	{
		std::cout	<< "\n-----------------Fraggy--------------\n" << std::flush;
		DiamondTrap	diamond("Diammy");
		diamond.attack("Minions");
		diamond.attack("Minions");
	}
}
