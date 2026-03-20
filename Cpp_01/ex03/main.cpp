#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		std::cout	<< "\n---------------------------------------test1---------------------------------\n" << std::flush;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout	<< "\n---------------------------------------test2---------------------------------\n" << std::flush;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("");
		jim.attack();
	}
	{
		std::cout	<< "\n---------------------------------------test3---------------------------------\n" << std::flush;
		Weapon saber = Weapon("sharpy thingy");
		HumanB jim("Jim");
		jim.attack();
		jim.attack();
	}
	return 0;
}
