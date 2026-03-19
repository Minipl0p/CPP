
#pragma once

#include <cstdio>
#include <iostream>
#include <ostream>

class	Fixed
{
	private:
		int					_number;
		static const int	_frac = 8;
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed&				operator=(const Fixed& copy);

		Fixed				operator+(const Fixed& nb) const;
		Fixed				operator-(const Fixed& nb) const;
		Fixed				operator*(const Fixed& nb) const;
		Fixed				operator/(const Fixed& nb) const;

		Fixed&				operator++();
		Fixed&				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);

		bool				operator<(const Fixed& copy) const;
		bool				operator>(const Fixed& copy) const;
		bool				operator<=(const Fixed& copy) const;
		bool				operator>=(const Fixed& copy) const;
		bool				operator!=(const Fixed& copy) const;
		bool				operator==(const Fixed& copy) const;

		float				toFloat() const;
		int					toInt() const;
		int					getRawBits() const;
		void				setRawBits(int const raw);

		static Fixed&		min(Fixed& f1, Fixed& f2)				{ return (f1 < f2 ? f1 : f2); }
		static const Fixed&	min(const Fixed& f1, const Fixed& f2)	{ return (f1 < f2 ? f1 : f2); }
		static Fixed&		max(Fixed& f1, Fixed& f2)				{ return (f1 > f2 ? f1 : f2); }
		static const Fixed&	max(const Fixed& f1, const Fixed& f2)	{ return (f1 > f2 ? f1 : f2); }
};

std::ostream&	operator<<(std::ostream& os, const Fixed& copy);
