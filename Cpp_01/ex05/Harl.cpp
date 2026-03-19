
#include "Harl.hpp"

void	Harl::complain(std::string	level)
{
	typedef	void (Harl::*fctn)();
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	fctn fctns[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
		if (levels[i] == level)
		{
			(this->*fctns[i])();
			break;
		}
}
