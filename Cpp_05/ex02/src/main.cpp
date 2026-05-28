
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    srand(time(0));

    // ═══════════════════════════════════════════
    // Test 1: ShrubberyCreationForm - cas normal
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 1: Shrubbery - grade suffisant ===" << std::endl;
    try {
        Bureaucrat          b("Alice", 130);
        ShrubberyCreationForm f("garden");
        std::cout << f << std::endl;
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 2: ShrubberyCreationForm - non signé
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 2: Shrubbery - form non signee ===" << std::endl;
    try {
        Bureaucrat          b("Bob", 1);
        ShrubberyCreationForm f("park");
        b.executeForm(f); // pas signé → erreur
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 3: ShrubberyCreationForm - grade trop bas pour signer
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 3: Shrubbery - grade trop bas pour signer ===" << std::endl;
    try {
        Bureaucrat          b("Charlie", 150);
        ShrubberyCreationForm f("forest");
        b.signForm(f); // grade 150 < requis 145 → echec
        b.executeForm(f);
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 4: ShrubberyCreationForm - grade trop bas pour executer
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 4: Shrubbery - grade trop bas pour executer ===" << std::endl;
    try {
        Bureaucrat          signer("Signer", 140);
        Bureaucrat          exec("Exec", 150);
        ShrubberyCreationForm f("hill");
        signer.signForm(f);
        exec.executeForm(f); // grade 150 > requis 137 → echec
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 5: RobotomyRequestForm - plusieurs essais (50/50)
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 5: Robotomy - 4 essais ===" << std::endl;
    try {
        Bureaucrat          b("Dave", 1);
        RobotomyRequestForm f("target");
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f);
        b.executeForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 6: RobotomyRequestForm - grade trop bas pour signer
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 6: Robotomy - grade trop bas pour signer ===" << std::endl;
    try {
        Bureaucrat          b("Eve", 100);
        RobotomyRequestForm f("robot");
        b.signForm(f); // grade 100 > requis 72 → echec
        b.executeForm(f);
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 7: PresidentialPardonForm - cas normal
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 7: Presidential - cas normal ===" << std::endl;
    try {
        Bureaucrat             b("Zaphod", 1);
        PresidentialPardonForm f("Ford Prefect");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 8: PresidentialPardonForm - grade trop bas pour executer
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 8: Presidential - grade trop bas pour executer ===" << std::endl;
    try {
        Bureaucrat             signer("Signer", 20);
        Bureaucrat             exec("Exec", 10);
        PresidentialPardonForm f("Arthur Dent");
        signer.signForm(f);
        exec.executeForm(f); // grade 10 > requis 5 → echec
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    // ═══════════════════════════════════════════
    // Test 9: AForm est abstraite (ne compile pas si décommenté)
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 9: AForm abstraite ===" << std::endl;
    // AForm f("test", 1, 1); // ← doit être impossible → erreur de compilation

    // ═══════════════════════════════════════════
    // Test 10: Constructeur invalide (grade hors limites)
    // ═══════════════════════════════════════════
    std::cout << "\n=== Test 10: Form avec grade invalide ===" << std::endl;
    try {
        ShrubberyCreationForm f("bad");
        RobotomyRequestForm   r("bad2");
        PresidentialPardonForm p("bad3");
        (void)f; (void)r; (void)p;
    } catch (std::exception& e) { std::cout << e.what() << std::endl; }

    std::cout << "\n=== Fin des tests ===" << std::endl;
    return 0;
}
