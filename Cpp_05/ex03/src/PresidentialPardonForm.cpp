
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5), _target(_target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getGradeLimit(), cpy.getExecLimit()), _target(cpy.getTarget()) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return *this;
	this->_target = src.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox, Zaphod is the former Doc" << std::endl;
}
