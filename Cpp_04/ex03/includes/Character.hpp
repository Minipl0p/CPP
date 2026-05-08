
#pragma once

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_slots[4];
		int _last_idx;
		std::string _name;
		AMateria *_floor[1000];
		int	_last_floor;
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &cpy);
		Character &operator=(const Character &src);
		~Character(void);

		std::string const &getName() const;

		void use(int idx, ICharacter& target);
		void drop(AMateria* m);
		void equip(AMateria* m);
		void unequip(int idx);
};
