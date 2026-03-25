
#include "AMateria.hpp"

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
}
AMateria::AMateria(const AMateria& src)
{
	_type = src._type;
}
AMateria::~AMateria()	{};

std::string	const& AMateria::getType() const
{
	return _type;
}
