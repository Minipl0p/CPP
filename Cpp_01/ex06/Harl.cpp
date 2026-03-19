
#include "Harl.hpp"

void	Harl::complain(std::string	level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	count = -1;
	while (++count < 4)
		if (levels[count] == level)
			break ;
	switch (count)
	{
		case 0:
			this->debug();
			[[fallthrough]];
		case 1:
			this->info();
			[[fallthrough]];
		case 2:
			this->warning();
			[[fallthrough]];
		case 3:
			this->error();
			break ;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
