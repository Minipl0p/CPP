
#pragma once

#include <string>

class	AAnimal
{
	protected:
		std::string	_type;
	public:
		virtual ~AAnimal();
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& src);
		AAnimal&	operator=(const AAnimal& src);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

