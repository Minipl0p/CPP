#include <string>
#include <iostream>

#ifndef HARL_HPP
#define HARL_HPP

#define DEBUGMSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFOMSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNINGMSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define ERRORMSG "This is unacceptable! I want to speak to the manager now."

class	Harl
{
	private:
		void	debug()	{std::cout	<< "[ DEBUG ] \n " << DEBUGMSG << std::endl; };
		void	info()	{std::cout	<< "[ INFO ] \n " << INFOMSG << std::endl; };
		void	warning()	{std::cout	<< "[ WARNING ] \n " << WARNINGMSG << std::endl; };
		void	error()	{std::cout	<< "[ ERROR ] \n " << ERRORMSG << std::endl; };
	public:
		Harl()	{};
		~Harl()	{};
		void	complain(std::string	level);
};

#endif
