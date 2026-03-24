
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat :	public AAnimal
{
	private:
		Brain	*brain;
	protected:
	public:
		~Cat();
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);

		virtual void	makeSound() const;
		void			setIdeas(int idx, const std::string& ideas);
		std::string		getIdeas(int idx) const;

};
