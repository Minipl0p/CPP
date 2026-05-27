
#include "../includes/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()	{}

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::string const  Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too high"); }

const char *Bureaucrat::GradeTooLowException::what() const throw()
{ return("\e[31mException\e[0m : The grade is too low"); }

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
