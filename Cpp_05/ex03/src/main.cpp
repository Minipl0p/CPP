
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

int main()
{
    Intern intern;

    // ═══════════════════════════════════════════
    // Test 1: Intern crée un ShrubberyCreationForm
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 1: Intern cree ShrubberyCreationForm ===" << std::endl;
    try {
        AForm* form = intern.makeForm("shrubbery creation", "garden");
        Bureaucrat b("Alice", 130);
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 2: Intern crée un RobotomyRequestForm
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 2: Intern cree RobotomyRequestForm ===" << std::endl;
    try {
        AForm* form = intern.makeForm("robotomy request", "Bender");
        Bureaucrat b("Dave", 1);
        b.signForm(*form);
        b.executeForm(*form);
        b.executeForm(*form);
        delete form;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 3: Intern crée un PresidentialPardonForm
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 3: Intern cree PresidentialPardonForm ===" << std::endl;
    try {
        AForm* form = intern.makeForm("presidential pardon", "Ford Prefect");
        Bureaucrat b("Zaphod", 1);
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 4: Intern reçoit un nom de form inconnu
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 4: Nom de form inconnu ===" << std::endl;
    try {
        AForm* form = intern.makeForm("unknown form", "target");
        delete form;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 5: Intern copy constructor / operator=
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 5: Copie d'Intern ===" << std::endl;
    try {
        Intern intern2(intern);
        Intern intern3;
        intern3 = intern2;
        AForm* form = intern3.makeForm("presidential pardon", "Arthur Dent");
        Bureaucrat b("Zaphod", 1);
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    std::cout << "\n=== Fin des tests ===" << std::endl;
    return 0;
}
