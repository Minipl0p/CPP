#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string str;
	PhoneBook ph;

	ph.nextIdx = 0;
	ph.count = 0;
	while (1)
	{
		std::cout	<< "Phonebook command : " << std::flush;
		if (!(std::getline(std::cin, str)))
			break ;
		else if (!str.compare("ADD"))
		{
			ph.addContact();
		}
		else if (!str.compare("SEARCH"))
		{
			ph.search();
		}
		else if (!str.compare("EXIT"))
			break ;
		else
			std::cout << "Wrong command !\n" << std::flush;
	}

	// ph.delContacts();
	return (0);
}
