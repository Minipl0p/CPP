
#include "../includes/easyfind.hpp"

#include <vector>
#include <sstream>

int printError(std::string msg, int error)
{
	std::cout << msg << std::endl;
	return error;
}

int main(int ac, char **av) {
	if (ac <= 2) {
		std::cout << "Usage : /EasyFind *<number_list> <number_to_find>" << std::endl;
		return (1);
	}

	std::vector<int> numbers;
	int search;
	int current;

	if (!(std::istringstream(av[ac - 1]) >> search))
		return (printError("This entry is not a int !", 1));

	for (int i = 0; i < ac - 2; i++) {
		if (!(std::istringstream(av[i + 1]) >> current))
			return (printError("This entry is not a int !", 1));
		numbers.push_back(current);
	}
	easyfind(numbers, search);
}
