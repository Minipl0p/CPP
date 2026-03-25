
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog :	public Animal
{
	private:
		Brain	*brain;
	protected:
	public:
		~Dog();
		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);

		virtual void	makeSound() const;
		void			setIdeas(int idx, const std::string& ideas);
		std::string		getIdeas(int idx) const;
};

