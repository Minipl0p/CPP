
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::~Dog()
{
	std::cout	<< "Dog destructor;" << std::endl;
	delete	this->brain;
}
Dog::Dog()							: AAnimal("Dog")
{
	this->brain = new Brain();
	std::cout	<< _type << " Dog Default_constuctor" << std::endl;
}
Dog::Dog(const Dog& src)			: AAnimal(src)
{
	this->brain = new Brain(*src.brain);
	_type = src._type;
	std::cout << _type << " Dog constructor by copy" << std::endl;
}
Dog&	Dog::operator=(const Dog& src)
{
	if (this == &src)
		return (*this);
	*this->brain = *src.brain;
	_type = src._type;
	return (*this);
}

void	Dog::makeSound() const	{ std::cout	<< "*Bark* *BAARK*" << std::endl; }
void			Dog::setIdeas(int idx, const std::string& ideas)	{ this->brain->setIdeas(idx, ideas); }
std::string		Dog::getIdeas(int idx) const						{ return this->brain->getIdeas(idx); }
