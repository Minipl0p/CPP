
#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string& name) { _name = name;  std::cout << this->_name << " is construct\n" << std::flush; }

Zombie::~Zombie()	{ std::cout << this->_name << " is delete\n" << std::flush; }

void	Zombie::announce() const
{
	std::cout	<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
