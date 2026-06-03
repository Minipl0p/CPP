
#include "../includes/ScalarConverter.hpp"

int main(void)
{
    // Cas speciaux
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");

    std::cout << "---" << std::endl;

    // Char
    ScalarConverter::convert("a");
    ScalarConverter::convert("*");
    ScalarConverter::convert("+");

    std::cout << "---" << std::endl;

    // Int
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("65");       // ASCII 'A'
    ScalarConverter::convert("2147483647");  // INT_MAX
    ScalarConverter::convert("2147483648");  // INT_MAX + 1

    std::cout << "---" << std::endl;

    // Float
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("42.1f");
    ScalarConverter::convert("-42.1f");
    ScalarConverter::convert("4.29999f");

    std::cout << "---" << std::endl;

    // Double
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("42.1");
    ScalarConverter::convert("-42.1");

    std::cout << "---" << std::endl;

    // Invalides
    ScalarConverter::convert("abc");
    ScalarConverter::convert("42.6fcoucou");
    ScalarConverter::convert("42f.1");
    ScalarConverter::convert("42.1.1");

    return 0;
}
