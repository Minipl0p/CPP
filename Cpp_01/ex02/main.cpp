#include <iomanip>
#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = *stringPTR;

	std::cout	<< std::setw(45) << std::left << "Memory address of the string variable : " << &str << std::endl
				<< std::setw(45) << std::left << "Memory address held by stringPTR : " << stringPTR << std::endl
				<< std::setw(45) << std::left << "Memory address held by stringREF : " << &stringREF << std::endl << std::endl;

	std::cout	<< std::setw(45) << std::left << "Value of string variable : " << str << std::endl
				<< std::setw(45) << std::left << "Value pointed to by strinPTR : " << *stringPTR << std::endl
				<< std::setw(45) << std::left << "Value pointed to by stringREF : " << stringREF << std::endl;
	return 0;
}
