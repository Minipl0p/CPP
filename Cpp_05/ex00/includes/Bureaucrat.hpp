
#pragma once

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		std::string const  getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &bureaucrat);
