
#pragma once

#include <string>

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		~WrongAnimal();
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal&	operator=(const WrongAnimal& src);

		std::string		getType() const;
		void	makeSound() const;
};

