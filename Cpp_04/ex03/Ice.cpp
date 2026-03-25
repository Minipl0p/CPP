
#include "Ice.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& src)
{
	_type = src._type;
}
Ice&	Ice::operator=(const Ice& src)
{
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}
Ice::~Ice()	{}

AMateria*	Ice::clone() const
{
	AMateria	*tmp = new Ice();
	return tmp;
}
void		Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at " << target.getName() << " *\n" << std::endl;
}
