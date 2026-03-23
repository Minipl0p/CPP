
#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::~Cat()											{ std::cout	<< "Cat destructor;" << std::endl; }
Cat::Cat()							: Animal("Cat")	{ std::cout	<< _type << " Cat Default_constuctor" << std::endl; }
Cat::Cat(const Cat& src)			: Animal(src)	{ _type = src._type; std::cout << _type << " Cat constructor by copy" << std::endl;}
Cat&	Cat::operator=(const Cat& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	Cat::makeSound() const		{ std::cout	<< "*Meow* *Meeeeeeeooooowwwwwwwwww*" << std::endl; }
