
#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);

		std::string	getTarget(void) const;
		void		executeAction(void) const;
};
