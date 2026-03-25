

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::~WrongCat()															{ std::cout	<< "WrongCat destructor;" << std::endl; }
WrongCat::WrongCat()							: WrongAnimal("WrongCat")		{ std::cout	<< _type << " WrongCat Default_constuctor" << std::endl; }
WrongCat::WrongCat(const WrongCat& src)			: WrongAnimal(src)	{ _type = src._type; std::cout << _type << " WrongCat constructor by copy" << std::endl;}
WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	WrongCat::makeSound() const		{ std::cout	<< "*Meow* *Meeeeeeeooooowwwwwwwwww*" << std::endl; }

