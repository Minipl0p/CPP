
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

#include <iostream>

int main(void)
{
	std::cout << "\n=== CAS 1 : test officiel du sujet ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n=== CAS 2 : inventaire plein ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		AMateria* rejected = src->createMateria("ice");
		hero->equip(rejected);
		delete rejected;

		delete hero;
		delete src;
	}

	std::cout << "\n=== CAS 3 : index invalide ===" << std::endl;
	{
		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");

		hero->use(0, *target);
		hero->use(42, *target);
		hero->unequip(0);
		hero->unequip(42);

		delete hero;
		delete target;
	}

	// ═══════════════════════════════════════════
	// CAS 4 : unequip puis re-equip
	// ═══════════════════════════════════════════
	std::cout << "\n=== CAS 4 : unequip puis re-equip ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");

		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		hero->use(0, *target);
		hero->unequip(0);
		hero->equip(src->createMateria("cure"));
		hero->use(0, *target);

		delete hero;
		delete target;
		delete src;
	}

	// ═══════════════════════════════════════════
	// CAS 5 : deep copy de Character
	// ═══════════════════════════════════════════
	std::cout << "\n=== CAS 5 : deep copy Character ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* a = new Character("A");
		a->equip(src->createMateria("ice"));
		a->equip(src->createMateria("cure"));

		Character* b = new Character(*a);
		ICharacter* target = new Character("target");

		b->use(0, *target);
		delete a;
		b->use(1, *target);

		Character* c = new Character("C");
		*c = *b;
		delete b;
		c->use(0, *target);

		delete c;
		delete target;
		delete src;
	}

	// ═══════════════════════════════════════════
	// CAS 6 : deep copy de MateriaSource
	// ═══════════════════════════════════════════
	std::cout << "\n=== CAS 6 : deep copy MateriaSource ===" << std::endl;
	{
		MateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		src1->learnMateria(new Cure());

		MateriaSource* src2 = new MateriaSource(*src1);
		delete src1;

		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");
		hero->equip(src2->createMateria("ice"));
		hero->equip(src2->createMateria("cure"));
		hero->use(0, *target);
		hero->use(1, *target);

		delete hero;
		delete target;
		delete src2;
	}

	// ═══════════════════════════════════════════
	// CAS 7 : type inconnu dans createMateria
	// ═══════════════════════════════════════════
	std::cout << "\n=== CAS 7 : type inconnu ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "createMateria(\"fire\") retourne NULL : OK" << std::endl;

		ICharacter* hero = new Character("hero");
		hero->equip(unknown);
		delete hero;
		delete src;
	}

	// ═══════════════════════════════════════════
	// CAS 8 : destruction via pointeur d'interface
	// ═══════════════════════════════════════════
	std::cout << "\n=== CAS 8 : delete via ICharacter* ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* hero = new Character("hero");
		hero->equip(src->createMateria("ice"));

		delete hero;
		delete src;
	}

	return 0;
}
