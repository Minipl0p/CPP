

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::~WrongCat()
{
	std::cout	<< "WrongCat destructor;" << std::endl;
	delete	this->brain;
}
WrongCat::WrongCat()					: WrongAnimal("WrongCat")
{
	this->brain = new Brain();
	std::cout	<< _type << " WrongCat Default_constuctor" << std::endl;
}
WrongCat::WrongCat(const WrongCat& src)	: WrongAnimal(src)
{
	this->brain = new Brain(*src.brain);
	_type = src._type;
	std::cout << _type << " WrongCat constructor by copy" << std::endl;
}
WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	if (this == &src)
		return (*this);
	*this->brain = *src.brain;
	_type = src._type;
	return (*this);
}

void	WrongCat::makeSound() const		{ std::cout	<< "*Meow* *Meeeeeeeooooowwwwwwwwww*" << std::endl; }

