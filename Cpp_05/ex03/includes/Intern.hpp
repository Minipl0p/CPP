
#pragma once

# include <string>
# include "AForm.hpp"

class Intern {

	private:
		AForm *createShrubbery(std::string const& target) const;
		AForm *createPresidential(std::string const& target) const;
		AForm *createRobotomy(std::string const& target) const;
	public:
		Intern(void);
		~Intern(void);
		Intern &operator=(const Intern &src);
		Intern(const Intern &cpy);
		AForm *makeForm(std::string const& formName, std::string const& target) const;
};
