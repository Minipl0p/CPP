
#pragma once

#include "Animal.hpp"

class	Cat :	public Animal
{
	protected:
	public:
		~Cat();
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);

		virtual void	makeSound() const;
};
