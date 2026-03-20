
#include "zombie.hpp"
#include <iostream>

Zombie	*zombieHorde(size_t N, std::string name)
{
	if (N == 0 || N >= 255)
	{
		std::cout << "Warning, N shoul'd be : 0 < N >= 255 " << std::endl;
		return (NULL);
	}

	Zombie	*zombieHorde = new Zombie[N];

	for	(size_t	i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return zombieHorde;
}
