#include <string>
#include <iostream>
#include "zombie.hpp"

Zombie::Zombie()	{}

Zombie::~Zombie()	{}

void	Zombie::setName(std::string name) { _name = name; }

void	Zombie::announce() const
{
	std::cout	<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
