
#include "ClapTrap.hpp"

ClapTrap();
ClapTrap(std::string name);
ClapTrap(const ClapTrap& cpy);
~ClapTrap();

ClapTrap&	operator=(const ClapTrap& obj);
void		attack(const	std::string& target);
void		takeDamage(unsigned int amount);
void		beRepaired(unsigned int amount);
