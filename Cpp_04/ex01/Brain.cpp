
#include "Brain.hpp"
#include <iostream>

Brain::~Brain()	{ std::cout << "Brain destructor" << std::endl; }
Brain::Brain()	{ std::cout	<< "Brain default constructor" << std::endl; }
Brain::Brain(const	Brain& src)
{
	std::cout	<< "Brain constructor by copy" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
}
Brain&	Brain::operator=(const Brain& src)
{
	if (this == &src)
		return *this;
	std::cout	<< "Brain constructor by operator" << std::endl;
	for (int i = 0; i < 100; i++)
		 _ideas[i] = src._ideas[i];
	return *this;
}
void			Brain::setIdeas(int idx, const std::string& ideas)
{
	if (idx < 0)
		idx *= -1;
	if (idx >= 100)
		idx = 99;
	_ideas[idx] = ideas;
}
std::string		Brain::getIdeas(int idx) const
{
	if (idx < 0)
		idx *= -1;
	if (idx >= 100)
		idx = 99;
	return _ideas[idx];
}
