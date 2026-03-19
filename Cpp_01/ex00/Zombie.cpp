
#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) { _name = name; }

Zombie::~Zombie()	{}

void	Zombie::announce() const
{
	std::cout	<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
