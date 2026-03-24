
#pragma once

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class	WrongCat :	public WrongAnimal
{
	private:
		Brain	*brain;
	protected:
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& src);

		void	makeSound() const;
};
