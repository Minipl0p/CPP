
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::~WrongAnimal()							{ std::cout	<< "WrongAnimal destructor;" << std::endl; }
WrongAnimal::WrongAnimal()							{ _type = "Generic"; std::cout	<< _type << " WrongAnimal Default_constructor" << std::endl; }
WrongAnimal::WrongAnimal(const std::string& type)	{ _type = type; std::cout << _type << " WrongAnimal constructor" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal& src)	{ _type = src._type; std::cout << _type << " WrongAnimal constructor by copy" << std::endl;}
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	WrongAnimal::makeSound() const		{ std::cout	<< "Sort of generic animal sound" << std::endl; }
std::string	WrongAnimal::getType() const		{ return _type; }
