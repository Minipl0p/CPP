
#pragma once

#include "WrongAnimal.hpp"

class	WrongCat :	public WrongAnimal
{
	protected:
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& src);

		void	makeSound() const;
};
