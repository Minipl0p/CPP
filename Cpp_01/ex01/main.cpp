#include "zombie.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

static	bool isValidArg(char *str)
{
	std::string	s = str;
	for	(std::string::iterator it = s.begin(); it != s.end(); it++)
		if (!std::isdigit(*it))
			return false;
	return true;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout	<< "Only one numeric arg";
		return 1;
	}
	if (!isValidArg(av[1]))
	{
		std::cout	<< "The arg should be an int (overflow not handled)";
		return 1;
	}
	int	N = std::atoi(av[1]);
	Zombie	*zHorde = zombieHorde(N, "Roger");
	for	(int i = 0; i < N; i++)
		zHorde[i].announce();
	delete[] zHorde;
}
