
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	{
		std::cout	<< "---------------TEST 1--------------------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout	<< "\n---------------TEST 3--------------------" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal*	k = new WrongCat();
		std::cout << k->getType() << " " << std::endl;
		k->makeSound();
		meta->makeSound();
		delete meta;
		delete k;
	}
	return 0;
}
