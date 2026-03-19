#include "Contact.hpp"

void	Contact::addNew(const std::string& first, const std::string& last, const std::string& nick,
			const std::string& number, const std::string& secret)
{
	this->setFirstName(first);
	this->setLastName(last);
	this->setNickname(nick);
	this->setNumber(number);
	this->setDarkestSecret(secret);
}

Contact::Contact() {};

void				Contact::setFirstName(const std::string& firstName)			{ _firstName = firstName; }

void				Contact::setLastName(const std::string& lastName)			{ _lastName = lastName; }

void				Contact::setNickname(const std::string& nickname)			{ _nickname = nickname; }

void				Contact::setNumber(const std::string& number)			{ _number = number; }

void				Contact::setDarkestSecret(const std::string& secret)		{ _darkestSecret = secret; }

const std::string&	Contact::getFirstName() const							{ return (_firstName); }

const std::string&	Contact::getLastName() const							{ return (_lastName); }

const std::string&	Contact::getNickname() const							{ return (_nickname); }

const std::string&	Contact::getNumber() const								{ return (_number); }

const std::string&	Contact::getDarkestSecret() const						{ return (_darkestSecret); }
