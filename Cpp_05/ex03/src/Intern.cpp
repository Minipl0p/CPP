
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern &cpy)
{ *this = cpy; }

Intern	&Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}

AForm *Intern::makeForm(std::string const& formName, std::string const& target) const
{
	if (target.empty())
	{
		std::cout << "Error: Target must be specified ''" << target << " is not recognized." << std::endl;
		throw std::invalid_argument("Error: Target must be specified and cannot be empty.");
	}
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreators[3])(std::string const&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			AForm* form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
	return NULL;
}

AForm *Intern::createShrubbery(std::string const& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string const& target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string const& target) const
{
	return new PresidentialPardonForm(target);
}
