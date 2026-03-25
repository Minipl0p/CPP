
#pragma once

#include <string>

class	Animal
{
	protected:
		std::string	_type;
	public:
		virtual ~Animal();
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& src);
		Animal&	operator=(const Animal& src);

		std::string		getType() const;
		virtual void	makeSound() const;
};

