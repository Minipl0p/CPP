
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main (void)
{
	{
		ClapTrap	clappy("Clappy");

		clappy.attack("Minions");
		clappy.attack("Minions");
		clappy.takeDamage(4);
		clappy.beRepaired(3);
		clappy.takeDamage(9999);
		clappy.beRepaired(99);
		clappy.takeDamage(1);
	}
	{
		std::cout	<< "\n-----------------Scavy--------------\n" << std::flush;
		ScavTrap	scavvy("Scavvy");
		scavvy.attack("Minions");
		scavvy.attack("Minions");
		scavvy.takeDamage(4);
		scavvy.beRepaired(3);
		scavvy.GuardGate();
		scavvy.takeDamage(9999);
		scavvy.beRepaired(99);
		scavvy.takeDamage(1);
		scavvy.GuardGate();
	}
}
