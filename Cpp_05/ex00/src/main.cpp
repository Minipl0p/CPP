
#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1 : création valide ---" << std::endl;
	try {
		Bureaucrat b("Alice", 42);
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2 : grade trop haut (0) ---" << std::endl;
	try {
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3 : grade trop bas (151) ---" << std::endl;
	try {
		Bureaucrat b("Charlie", 151);
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4 : increment jusqu'au max ---" << std::endl;
	try {
		Bureaucrat b("Dave", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade(); // grade 1 -> throw
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5 : decrement jusqu'au min ---" << std::endl;
	try {
		Bureaucrat b("Eve", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade(); // grade 150 -> throw
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6 : constructeur par défaut ---" << std::endl;
	try {
		Bureaucrat b;
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 7 : constructeur par copie ---" << std::endl;
	try {
		Bureaucrat a("Anne", 10);
		Bureaucrat b(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 8 : operator = ---" << std::endl;
	try {
		Bureaucrat a("Frank", 10);
		Bureaucrat b;
		b = a;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Test 9 : grades limites valides (1 et 150) ---" << std::endl;
	try {
		Bureaucrat high("Grace", 1);
		Bureaucrat low("Hank", 150);
		std::cout << high << std::endl;
		std::cout << low << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
