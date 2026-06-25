
#include "../includes/PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

static void	printVector(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i + 1 < vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> input;
	if (!PmergeMe::parseInput(argc, argv, input))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	printVector(input);

	clock_t start = clock();
	PmergeMe::sortVector(input);
	clock_t end = clock();

	std::cout << "After:  ";
	printVector(input);

	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << input.size()
			  << " elements with std::vector : "
			  << elapsed << " us" << std::endl;

	return 0;
}
