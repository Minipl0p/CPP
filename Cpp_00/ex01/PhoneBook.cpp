#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	readNonEmptyLine(const char *prompt, std::string &out)
{
	while (true)
	{
		std::cout << std::endl;
		std::cout << std::setw(35) << std::left << prompt << std::flush;
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "Field could'nt be empty, try again !" << std::endl;
	}
}

bool	PhoneBook::addContact()
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	number;
	std::string	secret;

	// SET ALL VARIABLE AND CHECK IF ALL OF THEM WORK
	if (!readNonEmptyLine("What is the first name ?", first))		return false;
	if (!readNonEmptyLine("What is the last name ?", last))			return false;
	if (!readNonEmptyLine("What is the nickname ?", nick))			return false;
	if (!readNonEmptyLine("What is the number ?", number))			return false;
	if (!readNonEmptyLine("What is the darkest secret ?", secret))	return false;

	// SET CLASS CONTACT WITH VARIABLES
	contacts[nextIdx].addNew(first, last, nick, number, secret);

	// INCREASE COUNT AND UPDATE NEXTIDX
	if (count < 8)
		count++;
	nextIdx = (nextIdx + 1) % 8;
	
	std::cout	<< "\n" << std::endl;
	return true;
}

static bool	readIdx(int &idx, int max)
{
	std::string	line;

	std::cout	<< "Index (0 - " << max << "): ";

// GET INDEX FROM USER AND PARS
	if (!(std::getline(std::cin, line)))
		return false;
	// Is line empty -> false
	if (line.empty())
		return false;
	// Is not only digit -> false
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
		if (!(std::isdigit(*it)))
			return false;

// CONVERT STRING PARSED TO NUMBER
	std::istringstream iss(line);
	int	value;
	iss >> value;

// IS INDEX PASSED AN EXISTING CONTACT ?
	if (value < 0 || value > max)
		return false;

	idx = value;
	return true;
}

static std::string formatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::search() const
{
	if (count <= 0)
	{
		std::cout	<< "No contact in the phonebook" << std::endl;
		return;
	}
// PRINT ARRAY OF CONTACT WITH INDEX
	std::cout << "|==========|==========|==========|==========|\n" << std::flush;
	std::cout << "|Index     |First Name|Last Name |Nickname  |\n" << std::flush;
	std::cout << "|==========|==========|==========|==========|\n" << std::flush;
	for (int i = 0; i < count; i++)
	{
		std::cout	<< "|"
					<< std::setw(10) << i << "|"
					<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getLastName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getNickname()) << "|"
					<< "\n|==========|==========|==========|==========|\n" << std::flush;
	}

// ASK THE USER FOR THE CONTACT HE WANT
	int	idx;
	if (!(readIdx(idx, count - 1)))
	{
		std::cout	<< "Invalid index or input ended.\n" << std::flush;
		return ;
	}

// PRINT THE CONTACT
	Contact	c = contacts[idx];

	std::cout	<< "first name : " << c.getFirstName() << "\n"
				<< "last name : " << c.getLastName() << "\n"
				<< "nickname : " << c.getNickname() << "\n"
				<< "number : " << c.getNumber() << "\n"
				<< "darkest secret : " << c.getDarkestSecret() << std::endl;
}
