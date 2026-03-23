
#include "Harl.hpp"
#include <iostream>

void	Harl::debug()	{std::cout	<< DEBUGMSG << std::endl; };
void	Harl::info()	{std::cout	<< INFOMSG << std::endl; };
void	Harl::warning()	{std::cout	<< WARNINGMSG << std::endl; };
void	Harl::error()	{std::cout	<< ERRORMSG << std::endl; };

Harl::Harl()	{};
Harl::~Harl()	{};

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
