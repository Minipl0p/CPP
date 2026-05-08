
#include <iostream>

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &src) : AMateria("cure_src")
{
	*this = src;
}

Cure	&Cure::operator=(const Cure &src)
{
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

std::string const &Cure::getType() const
{
	return this->_type;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}
