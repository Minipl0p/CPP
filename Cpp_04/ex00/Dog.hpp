
#pragma once

#include "Animal.hpp"

class	Dog :	public Animal
{
	protected:
	public:
		~Dog();
		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);

		virtual void	makeSound() const;
};

