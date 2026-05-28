
#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);

		std::string	getTarget(void) const;
		void		executeAction(void) const;
};
