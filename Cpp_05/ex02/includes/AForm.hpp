
#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				isSigned;
		const int			signGradeLimit;
		const int			signExecLimit;
	public:
		AForm();
		AForm(const std::string& name, int signGradeLimit, int signExecLimit);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		~AForm();

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeLimit() const;
		int					getExecLimit() const;
		void				beSigned(const Bureaucrat& people);
		void				execute(Bureaucrat const & executor) const;
		virtual void		executeAction(void) const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {

			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, AForm const &form);
