
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::~Dog()											{ std::cout	<< "Dog destructor;" << std::endl; }
Dog::Dog()							: Animal("Dog")	{ std::cout	<< _type << " Dog Default_constuctor" << std::endl; }
Dog::Dog(const Dog& src)			: Animal(src)	{ _type = src._type; std::cout << _type << " Dog constructor by copy" << std::endl;}
Dog&	Dog::operator=(const Dog& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	Dog::makeSound() const		{ std::cout	<< "*Bark* *BARK*" << std::endl; }
