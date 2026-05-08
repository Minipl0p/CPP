
#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria    *_slots[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& cpy);
		MateriaSource& operator=(const MateriaSource& src);
		~MateriaSource(void);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const& type);
};
