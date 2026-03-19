
#pragma once

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

		Fixed&			operator=(const Fixed& copy);
		float			toFloat() const;
		int				toInt() const;
		int				getRawBits() const;
		void			setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& copy);
