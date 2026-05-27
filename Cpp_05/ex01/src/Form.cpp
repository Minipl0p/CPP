
#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

Form::Form(): _name("default"), signGradeLimit(150), signExecLimit(150)
{
	isSigned = false;
}

Form::Form(const std::string& name, int signGradeLimit, int signExecLimit):
	_name(name), signGradeLimit(signGradeLimit), signExecLimit(signExecLimit)
{
	isSigned = false;
	if (signGradeLimit < 1 || signExecLimit < 1)
		throw GradeTooHighException();
	if (signGradeLimit > 150 || signExecLimit > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src): 
	_name(src._name), signGradeLimit(src.signGradeLimit), signExecLimit(src.signExecLimit)
{
	this->isSigned = src.isSigned;
	if (signGradeLimit < 1 || signExecLimit < 1)
		throw GradeTooHighException();
	if (signGradeLimit > 150 || signExecLimit > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& src)
{
	if (this == &src)
		return *this;
	this->isSigned = src.isSigned;
	return *this;
}

Form::~Form() {}

std::string const	Form::getName() const		{return this->_name; }
bool				Form::getSigned() const		{return this->isSigned; }
int					Form::getGradeLimit() const	{return this->signGradeLimit; }
int					Form::getExecLimit() const	{return this->signExecLimit; }

void				Form::beSigned(const Bureaucrat& people)
{
	if (people.getGrade() > this->getGradeLimit())
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too high"); }

const char *Form::GradeTooLowException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too low"); }

std::ostream	&operator<<(std::ostream& os, Form const &form)
{
	os << form.getName();
	form.getSigned() ?	os << " is signed " : os << " is not signed ";
	os << "should be signed by a Bureaucrat graded at least " << form.getGradeLimit() << " and exec by a Bureaucrat graded " << form.getExecLimit();
	return os;
}
