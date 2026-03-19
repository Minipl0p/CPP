
#include "Fixed.hpp"
#include <cmath>
#include <ostream>

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

std::ostream&	operator<<(std::ostream& os, const Fixed& copy)
{
	os << copy.toFloat();
	return (os);
}


Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n" << std::flush;
	*this = copy;
}

void	Fixed::setRawBits(int const raw) { _number = raw; }

Fixed::~Fixed()	{ std::cout << "Destructor called\n" << std::flush; }

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called\n" << std::flush;
	int n = nb;
	_number = roundf(n << _frac);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called\n" << std::flush;
	float n = nb;
	_number = roundf(static_cast<int>(n * (1 << _frac)));
}

float	Fixed::toFloat() const { return (static_cast<float>(_number / (1 << _frac))); }

int		Fixed::toInt() const { return (static_cast<int>(_number / (1 << _frac))); }
