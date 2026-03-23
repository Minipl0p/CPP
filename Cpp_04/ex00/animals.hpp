
#pragma once

#include <string>

class	Animal
{
	protected:
		std::string	_type;
	public:
		virtual ~Animal();
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& src);
		Animal&	operator=(const Animal& src);

		std::string		getType() const;
		virtual void	makeSound() const;
};

class	Dog :	public Animal
{
	protected:
	public:
		~Dog();
		Dog();
		Dog(const Dog& src);
		Dog&	operator=(const Dog& src);

		virtual void	makeSound() const;
};

class	Cat :	public Animal
{
	protected:
	public:
		~Cat();
		Cat();
		Cat(const Cat& src);
		Cat&	operator=(const Cat& src);

		virtual void	makeSound() const;
};

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		~WrongAnimal();
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal&	operator=(const WrongAnimal& src);

		std::string		getType() const;
		void	makeSound() const;
};

class	WrongCat :	public WrongAnimal
{
	protected:
	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& src);

		void	makeSound() const;
};
