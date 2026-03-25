
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

		void			setIdeas(int idx, const std::string& ideas);
		std::string		getIdeas(int idx) const;
};
