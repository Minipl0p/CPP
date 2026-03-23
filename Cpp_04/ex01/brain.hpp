
#pragma once

#include <string>

class	Brain
{
	protected:
		std::string	_ideas[100];
	public:
		~Brain();
		Brain();
		Brain(const	Brain& src);
		Brain&	operator=(const Brain& src);
};
