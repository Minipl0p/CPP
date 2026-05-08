
#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	_type = "Common Materia";
}
AMateria::AMateria(std::string const& type)
{
	_type = type;
}
AMateria&	AMateria::operator=(const AMateria& src)
{
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}

AMateria::AMateria(const AMateria& src)
{
	this->_type = src._type;
	*this = src;
}
AMateria::~AMateria()	{};

std::string	const& AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}
