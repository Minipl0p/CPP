
#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::~Cat()
{
	std::cout	<< "Cat destructor" << std::endl;
	delete	this->brain;
}
Cat::Cat()							: AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout	<< _type << " Cat Default_constuctor" << std::endl;
}
Cat::Cat(const Cat& src)			: AAnimal(src)
{
	this->brain = new Brain(*src.brain);
	_type = src._type;
	std::cout << _type << " Cat constructor by copy" << std::endl;
}
Cat&	Cat::operator=(const Cat& src)
{
	if (this == &src)
		return (*this);
	*this->brain = *src.brain;
	_type = src._type;
	return (*this);
}
void	Cat::makeSound() const	{ std::cout	<< "*Meow* *Meeeeeeeooooowwwwwwwwww*" << std::endl; }
void			Cat::setIdeas(int idx, const std::string& ideas)	{ this->brain->setIdeas(idx, ideas); }
std::string		Cat::getIdeas(int idx) const						{ return this->brain->getIdeas(idx); }
