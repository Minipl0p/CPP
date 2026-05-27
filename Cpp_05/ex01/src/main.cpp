
#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Test 1: Form valide ===" << std::endl;
	try {
		Form f("TaxForm", 50, 25);
		std::cout << f << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 2: Form grade trop haut (0) ===" << std::endl;
	try {
		Form f("BadForm", 0, 25);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 3: Form grade trop bas (151) ===" << std::endl;
	try {
		Form f("BadForm", 50, 151);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 4: Bureaucrat signe avec grade suffisant ===" << std::endl;
	try {
		Bureaucrat b("Alice", 30);
		Form f("TaxForm", 50, 25);
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 5: Bureaucrat grade insuffisant ===" << std::endl;
	try {
		Bureaucrat b("Bob", 100);
		Form f("TaxForm", 50, 25);
		b.signForm(f);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 6: Formulaire deja signe ===" << std::endl;
	try {
		Bureaucrat b("Alice", 1);
		Form f("TaxForm", 50, 25);
		b.signForm(f);
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n=== Test 7: Copy constructor ===" << std::endl;
	try {
		Form f1("Contract", 40, 20);
		Form f2(f1);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	return 0;
}
