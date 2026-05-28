
#include "../includes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), cpy.getGradeLimit(), cpy.getExecLimit()), _target(cpy.getTarget()) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;
	this->_target = src.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::executeForm(void) const
{
	std::cout << "BZZZZZT... DRRRRR... VRRRIIIIING... KRSHHHHH!" << std::endl;
	srand(time(0));
	if (rand() % 2 == 1)
		std::cout << this->getTarget() << " has been robotimized succesfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
