
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	{
		std::cout	<< "\n-----------------Fraggy--------------\n" << std::flush;
		FragTrap	fraggy("Scavvy");
		fraggy.attack("Minions");
		fraggy.attack("Minions");
		fraggy.takeDamage(4);
		fraggy.beRepaired(3);
		fraggy.HighFivesGuys();
		fraggy.takeDamage(9999);
		fraggy.beRepaired(99);
		fraggy.takeDamage(1);
		fraggy.HighFivesGuys();
	}
	{
		std::cout	<< "\n-----------------Fraggy--------------\n" << std::flush;
		DiamondTrap	diamond("Diammy");
		diamond.attack("Minions");
		diamond.attack("Minions");
		diamond.takeDamage(4);
		diamond.beRepaired(3);
		diamond.GuardGate();
		diamond.HighFivesGuys();
		diamond.whoAmI();
		diamond.takeDamage(9999);
		diamond.beRepaired(99);
		diamond.takeDamage(1);
		diamond.GuardGate();
		diamond.HighFivesGuys();
		diamond.whoAmI();
	}
}
