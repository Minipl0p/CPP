
#include "Zombie.hpp"

int	main(void)
{
	randomChump("Bernardo");

	Zombie *z = newZombie("Robert");

	z->announce();
	delete z;
}
