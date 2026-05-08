
#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& cpy);
		Cure& operator=(const Cure& src);
		~Cure();

		AMateria *clone() const;
		std::string const &getType() const;
		void use(ICharacter &target);
};
