
#include "animals.hpp"
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

// DOG PART ------------------------------------------------------------

Dog::~Dog()											{ std::cout	<< "Dog destructor;" << std::endl; }
Dog::Dog()							: Animal("Dog")		{ std::cout	<< _type << " Dog Default_constuctor" << std::endl; }
Dog::Dog(const Dog& src)			: Animal(src)	{ _type = src._type; std::cout << _type << " Dog constructor by copy" << std::endl;}
Dog&	Dog::operator=(const Dog& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	Dog::makeSound() const		{ std::cout	<< "*Bark* *BARK*" << std::endl; }

// CAT PART ------------------------------------------------------------

Cat::~Cat()											{ std::cout	<< "Cat destructor;" << std::endl; }
Cat::Cat()							: Animal("Cat")		{ std::cout	<< _type << " Cat Default_constuctor" << std::endl; }
Cat::Cat(const Cat& src)			: Animal(src)	{ _type = src._type; std::cout << _type << " Cat constructor by copy" << std::endl;}
Cat&	Cat::operator=(const Cat& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	Cat::makeSound() const		{ std::cout	<< "*Meow* *Meeeeeeeooooowwwwwwwwww*" << std::endl; }

// WRONG PART ----------------------------------------------------------

WrongAnimal::~WrongAnimal()						{ std::cout	<< "WrongAnimal destructor;" << std::endl; }
WrongAnimal::WrongAnimal()						{ _type = "Generic"; std::cout	<< _type << " WrongAnimal Default_constructor" << std::endl; }
WrongAnimal::WrongAnimal(const std::string& type)	{ _type = type; std::cout << _type << " WrongAnimal constructor" << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal& src)		{ _type = src._type; std::cout << _type << " WrongAnimal constructor by copy" << std::endl;}
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void	WrongAnimal::makeSound() const		{ std::cout	<< "Sort of generic animal sound" << std::endl; }
std::string	WrongAnimal::getType() const		{ return _type; }

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
