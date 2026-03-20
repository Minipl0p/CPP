
#include "ClapTrap.hpp"

int	main (void)
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
