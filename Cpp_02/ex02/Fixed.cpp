
#include "Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed()	: _number(0)	{}

int	Fixed::getRawBits() const { return _number; }

Fixed& Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
		_number = copy.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& copy) { os << copy.toFloat(); return (os); }

Fixed::Fixed(const Fixed& copy) { *this = copy; }

void	Fixed::setRawBits(int const raw) { _number = raw; }

Fixed::~Fixed()	{}

Fixed::Fixed(const int nb) { int n = nb; _number = n << _frac; }

Fixed::Fixed(const float nb) { float n = nb; _number = static_cast<int>(roundf((n * (1 << _frac)))); }

float	Fixed::toFloat() const { return (((float)_number / (1 << _frac))); }

int		Fixed::toInt() const { return ((_number / (1 << _frac))); }


bool				Fixed::operator<(const Fixed& copy) const	{ return (this->getRawBits() < copy.getRawBits()); }
bool				Fixed::operator>(const Fixed& copy) const	{ return (this->getRawBits() > copy.getRawBits()); }
bool				Fixed::operator<=(const Fixed& copy) const	{ return (this->getRawBits() <= copy.getRawBits()); }
bool				Fixed::operator>=(const Fixed& copy) const	{ return (this->getRawBits() >= copy.getRawBits()); }
bool				Fixed::operator!=(const Fixed& copy) const	{ return (this->getRawBits() != copy.getRawBits()); }
bool				Fixed::operator==(const Fixed& copy) const	{ return (this->getRawBits() == copy.getRawBits()); }

Fixed				Fixed::operator+(const Fixed& nb) const		{ return (Fixed(this->getRawBits() + nb.getRawBits())); }
Fixed				Fixed::operator-(const Fixed& nb) const		{ return (Fixed(this->getRawBits() - nb.getRawBits())); }
Fixed				Fixed::operator/(const Fixed& nb) const		{ return (Fixed((this->getRawBits() << _frac) / nb.getRawBits())); }
Fixed				Fixed::operator*(const Fixed& nb) const
{
	Fixed	res;
	res.setRawBits((this->getRawBits() * nb.getRawBits()) >> _frac);
	return (res);
}

Fixed&				Fixed::operator++()		{ _number += 1; return *this; }
Fixed				Fixed::operator++(int)	{ Fixed tmp = *this; _number += 1; return tmp; }
Fixed&				Fixed::operator--()		{ _number -= 1; return *this; }
Fixed				Fixed::operator--(int)	{ Fixed tmp = *this; _number -= 1; return tmp; }
