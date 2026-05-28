
#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);

		std::string	getTarget(void) const;
		void		executeForm(void) const;
};
