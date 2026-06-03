
#include "../includes/ScalarConverter.hpp"
#include <iostream>

#define GRAY  "\033[90m"
#define RED   "\033[1;31m"
#define RESET "\033[0m"

static void printTest(const std::string &input,
                      const std::string &eChar,
                      const std::string &eInt,
                      const std::string &eFloat,
                      const std::string &eDouble)
{
    std::cout << GRAY << input << RESET << std::endl;
    std::cout << GRAY "attendu: " RED "char: "   << eChar   << RESET << std::endl;
    std::cout << GRAY "attendu: " RED "int: "    << eInt    << RESET << std::endl;
    std::cout << GRAY "attendu: " RED "float: "  << eFloat  << RESET << std::endl;
    std::cout << GRAY "attendu: " RED "double: " << eDouble << RESET << std::endl;
    ScalarConverter::convert(input);
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    if (argc != 1)
        return 0;

    printTest("nan",        "impossible", "impossible", "nanf",    "nan");
    printTest("nanf",       "impossible", "impossible", "nanf",    "nan");
    printTest("+inf",       "impossible", "impossible", "+inff",   "+inf");
    printTest("+inff",      "impossible", "impossible", "+inff",   "+inf");
    printTest("-inf",       "impossible", "impossible", "-inff",   "-inf");
    printTest("-inff",      "impossible", "impossible", "-inff",   "-inf");

    printTest("a",          "'a'",        "97",         "97.0f",   "97.0");
    printTest("*",          "'*'",        "42",         "42.0f",   "42.0");
    printTest("+",          "'+'",        "43",         "43.0f",   "43.0");

    printTest("0",          "Non displayable", "0",    "0.0f",    "0.0");
    printTest("42",         "'*'",        "42",         "42.0f",   "42.0");
    printTest("-42",        "impossible", "-42",        "-42.0f",  "-42.0");
    printTest("65",         "'A'",        "65",         "65.0f",   "65.0");
    printTest("2147483647", "impossible", "2147483647", "2147483648.0f", "2147483647.0");
    printTest("2147483648", "impossible", "impossible", "impossible",   "impossible");

    printTest("42.0f",      "'*'",        "42",         "42.0f",   "42.0");
    printTest("42.1f",      "'*'",        "42",         "42.1f",   "42.1");
    printTest("-42.1f",     "impossible", "-42",        "-42.1f",  "-42.1");
    printTest("4.29999f",   "impossible", "4",          "4.29999f","4.29999");

    printTest("42.0",       "'*'",        "42",         "42.0f",   "42.0");
    printTest("42.1",       "'*'",        "42",         "42.1f",   "42.1");
    printTest("-42.1",      "impossible", "-42",        "-42.1f",  "-42.1");

    printTest("abc",        "impossible", "impossible", "impossible", "impossible");
    printTest("42.6fcoucou","impossible", "impossible", "impossible", "impossible");
    printTest("42f.1",      "impossible", "impossible", "impossible", "impossible");
    printTest("42.1.1",     "impossible", "impossible", "impossible", "impossible");

    return 0;
}
