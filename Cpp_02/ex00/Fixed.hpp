
#pragma once

class	Fixed
{
	private:
		int					_number;
		static const int	_frac = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed&	operator=(const Fixed& copy);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};
