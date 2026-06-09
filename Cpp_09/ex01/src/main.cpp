
#include "../includes/RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	RPN rpn;

	if (ac < 2) {
		std::cerr << "Usage : /RPN <mathematical_expression>" << std::endl;
		return 1;
	}
	else if (ac > 2) {
		int j = 0;
		for (int i = 0; i < (ac - 2); i++)
		{
			while (av[1][++j]);
			av[1][j] = ' ';
		}
	}
	try {
		std::cout << rpn.solveRPN(av[1]) << std::endl;
	} catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
