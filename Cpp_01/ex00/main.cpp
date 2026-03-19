
#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = newZombie("Roger");

	z->announce();
	randomChump("Bernardo");
	delete z;
}
