#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];

public:
	int		nextIdx;
	int		count;
	bool	addContact();
	void	search() const;
	void	delContacts();
};

#endif
