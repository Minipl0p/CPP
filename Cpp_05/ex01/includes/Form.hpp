
#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				isSigned;
		const int			signGradeLimit;
		const int			signExecLimit;
	public:
		Form();
		Form(const std::string& name, int signGradeLimit, int signExecLimit);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeLimit() const;
		int					getExecLimit() const;
		void				beSigned(const Bureaucrat& people);

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, Form const &form);
