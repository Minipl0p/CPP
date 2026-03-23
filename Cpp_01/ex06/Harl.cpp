
#include "Harl.hpp"
#include <iostream>

void	Harl::debug()	{std::cout	<< "[ DEBUG ]\n" << DEBUGMSG << std::endl; };
void	Harl::info()	{std::cout	<< "[ INFO ]\n" << INFOMSG << std::endl; };
void	Harl::warning()	{std::cout	<< "[ WARNING ]\n" << WARNINGMSG << std::endl; };
void	Harl::error()	{std::cout	<< "[ ERROR ]\n" << ERRORMSG << std::endl; };

Harl::Harl()	{};
Harl::~Harl()	{};

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
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
