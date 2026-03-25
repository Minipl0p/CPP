
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

int	main()
{
	//Constructing animals
	Animal	*arr[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}

	//Testing animals
	for (int i = 0; i < 10; i++)
	{
		std::cout	<< arr[i]->getType() << "No : " << i << "says :\t" << std::flush;
		arr[i]->makeSound();
		std::cout	<< std::endl;
	}
	//deleting like the subject ask
	for (int i = 0; i < 10; i++)
		delete arr[i];

	std::cout	<< std::endl;

	Dog	*doggy = new Dog();
	doggy->setIdeas(0, "I think, so i want food");
	doggy->setIdeas(1, "BOOOOOOOOOONNNNNNNESSSSSSSSS");
	doggy->setIdeas(2, "Pet me Pet me Pet me Pet me Pet me Pet me Pet me Pet me Pet me Pet me Pet me Pet me");
	for (int i = 0; i < 5; i++)
		std::cout	<< i << "st ideas is : "<<	doggy->getIdeas(i) << std::endl;
	delete doggy;

	return 0;
}
