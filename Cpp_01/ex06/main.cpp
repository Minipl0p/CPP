
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Invalid numbers of args" << std::endl, 1);

	Harl *h = new Harl;
	h->complain(av[1]);
	delete h;
}
