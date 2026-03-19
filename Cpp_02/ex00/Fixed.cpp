
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()	: _number(0)	{ std::cout	<< "Default constructor called\n" << std::flush; }

int	Fixed::getRawBits() const
{
	std::cout << "GetRawBits member function called\n" << std::flush;
	return _number;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout <<	"Copy assignement operator called\n" << std::flush;
	if (this != &copy)
		_number = copy.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n" << std::flush;
	*this = copy;
}

void	Fixed::setRawBits(int const raw)
{
	_number = raw;
}

Fixed::~Fixed()	{ std::cout << "Destructor called\n" << std::flush; }
