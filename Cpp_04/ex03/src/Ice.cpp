
#include <iostream>

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(const Ice &src) : AMateria("ice_src")
{
	*this = src;
}

Ice	&Ice::operator=(const Ice &src)
{
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

std::string const &Ice::getType() const
{
	return this->_type;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl; 
}
