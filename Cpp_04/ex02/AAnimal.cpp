
#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::~AAnimal()						{ std::cout	<< "Animal destructor;" << std::endl; }
AAnimal::AAnimal()						{ _type = "Generic"; std::cout	<< _type << " Animal Default_constructor" << std::endl; }
AAnimal::AAnimal(const std::string& type)	{ _type = type; std::cout << _type << " Animal constructor" << std::endl; }
AAnimal::AAnimal(const AAnimal& src)		{ _type = src._type; std::cout << _type << " Animal constructor by copy" << std::endl;}
AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

std::string	AAnimal::getType() const		{ return _type; }
