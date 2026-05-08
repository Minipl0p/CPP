
#include <iostream>
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

int	main(void)
{
	std::cout << std::endl << "############ creating a new spellbook ############" << std::endl << std::endl;
	MateriaSource *spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());

	std::cout << std::endl << "############ copying spellbook ############" << std::endl << std::endl;
	IMateriaSource *spellBookCopy = new MateriaSource(*spellBook);

	std::cout << std::endl << "############ learn new spells in spellbook ############" << std::endl << std::endl;
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());

	std::cout << std::endl << "############ learn new spells in spellbook-copy ############" << std::endl << std::endl;
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());

	std::cout << std::endl << "############ creating the new character Bomboclat ############" << std::endl << std::endl;
	AMateria *tmp;
	Character *Bomboclat = new Character("Bomboclat");

	tmp = spellBookCopy->createMateria("cure");
	Bomboclat->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Bomboclat->equip(tmp);



	std::cout << std::endl << "############ copy the a new character Bomboclat ############" << std::endl << std::endl;
	Character *BomboclatCopy = new Character(*Bomboclat);

	BomboclatCopy->use(1, *Bomboclat);
	BomboclatCopy->use(0, *Bomboclat);
	Bomboclat->unequip(1);
	delete tmp;


	std::cout << std::endl << "############ creating a new character DarckVador ############" << std::endl << std::endl;
	ICharacter* darckvador = new Character("DarckVador");

	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	delete tmp;

	std::cout << std::endl << "############ creating a new character SpongeBob ############" << std::endl << std::endl;
	ICharacter *spongebob = new Character("SpongeBob");
	darckvador->use(0, *spongebob);
	darckvador->use(1, *spongebob);
	spongebob->use(0, *darckvador);
	spongebob->use(1, *darckvador);

	std::cout << std::endl << "############ destroying Bomboclat-copy ############" << std::endl << std::endl;
	delete BomboclatCopy;

	std::cout << std::endl << "############ destroying Bomboclat-copy ############" << std::endl << std::endl;
	delete Bomboclat;

	std::cout << std::endl << "############ destroying SpongeBob ############" << std::endl << std::endl;
	delete spongebob;

	std::cout << std::endl << "############ destroying DarckVador ############" << std::endl << std::endl;
	delete darckvador;

	std::cout << std::endl << "############ destroying spellbook ############" << std::endl << std::endl;
	delete spellBook;

	std::cout << std::endl << "############ destroying spellbook Copy ############" << std::endl << std::endl;
	delete spellBookCopy;
	return (0);
}
