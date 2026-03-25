
#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::~Animal()						{ std::cout	<< "Animal destructor;" << std::endl; }
Animal::Animal()						{ _type = "Generic"; std::cout	<< _type << " Animal Default_constructor" << std::endl; }
Animal::Animal(const std::string& type)	{ _type = type; std::cout << _type << " Animal constructor" << std::endl; }
Animal::Animal(const Animal& src)		{ _type = src._type; std::cout << _type << " Animal constructor by copy" << std::endl;}
Animal&	Animal::operator=(const Animal& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	Animal::makeSound() const		{ std::cout	<< "Sort of generic animal sound" << std::endl; }
std::string	Animal::getType() const		{ return _type; }
