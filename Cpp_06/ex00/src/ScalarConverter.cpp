
#include "../includes/ScalarConverter.hpp"
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) { (void)cpy;}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) {(void)src; return *this;}

void ScalarConverter::convert(std::string str)
{
	int len;

	len = str.length();

	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}

	if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	if (len == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
		char c = str[0];
		std::cout << "char: \'" << c << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	char *end;
	long int i = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && i >= INT_MIN && i <= INT_MAX) {
		if (i >= 0 && i <= 255 && !std::isprint(i))
			std::cout << "char: Non displayable" << std::endl;
		else 
			std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return;
	}

	if (*end != '.')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	double d = std::strtod(str.c_str(), &end);
	if (*end == '\0') {
		std::cout << "char: ";
		if (static_cast<int>(d) >= 0 && static_cast<int>(d) <= 255 && std::isprint(static_cast<int>(d)))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "int: ";
		if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "float: ";
		if (d > FLT_MAX)
			std::cout << "+inff" << std::endl;
		else if (d < -FLT_MAX)
			std::cout << "-inff" << std::endl;
		else if (d == static_cast<int>(d))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << static_cast<float>(d) << "f" << std::endl;

		std::cout << "double: ";
		if (d == static_cast<int>(d))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
		else
			std::cout << static_cast<double>(d) << std::endl;
		return;
	}

	if (*end == 'f') {
		float	f = static_cast<float>(d);

		std::cout << "char: ";
		if (static_cast<int>(f) >= 0 && static_cast<int>(f) <= 255 && std::isprint(static_cast<int>(f)))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "int: ";
		if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
			std::cout << static_cast<int>(f) << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "float: ";
		if (f == static_cast<int>(f))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
		else
			std::cout << static_cast<float>(f) << "f" << std::endl;

		std::cout << "double: ";
		if (f == static_cast<int>(f))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
		else
			std::cout << static_cast<double>(f) << std::endl;
		return;  
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return ;
}
