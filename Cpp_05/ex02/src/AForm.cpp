
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

AForm::AForm(): _name("default"), signGradeLimit(150), signExecLimit(150)
{
	isSigned = false;
}

AForm::AForm(const std::string& name, int signGradeLimit, int signExecLimit):
	_name(name), signGradeLimit(signGradeLimit), signExecLimit(signExecLimit)
{
	isSigned = false;
	if (signGradeLimit < 1 || signExecLimit < 1)
		throw GradeTooHighException();
	if (signGradeLimit > 150 || signExecLimit > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src): 
	_name(src._name), signGradeLimit(src.signGradeLimit), signExecLimit(src.signExecLimit)
{
	this->isSigned = src.isSigned;
	if (signGradeLimit < 1 || signExecLimit < 1)
		throw GradeTooHighException();
	if (signGradeLimit > 150 || signExecLimit > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& src)
{
	if (this == &src)
		return *this;
	this->isSigned = src.isSigned;
	return *this;
}

AForm::~AForm() {}

std::string const	AForm::getName() const		{return this->_name; }
bool				AForm::getSigned() const		{return this->isSigned; }
int					AForm::getGradeLimit() const	{return this->signGradeLimit; }
int					AForm::getExecLimit() const	{return this->signExecLimit; }

void				AForm::beSigned(const Bureaucrat& people)
{
	if (people.getGrade() > this->getGradeLimit())
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecuteNeed())
		throw AForm::GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too high"); }

const char *AForm::GradeTooLowException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too low"); }

const char *AForm::FormNotSignedException::what() const throw()
{ return("\e[31mException\e[0m : The form is not signed !"); }

std::ostream	&operator<<(std::ostream& os, AForm const &form)
{
	os << form.getName();
	form.getSigned() ?	os << " is signed " : os << " is not signed ";
	os << "should be signed by a Bureaucrat graded at least " << form.getGradeLimit() << " and exec by a Bureaucrat graded " << form.getExecLimit();
	return os;
}
