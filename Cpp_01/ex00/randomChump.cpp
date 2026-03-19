
#include "Zombie.hpp"

void	randomChump(std::string	name)
{
	Zombie tmp = Zombie(name);

	tmp.announce();
}
