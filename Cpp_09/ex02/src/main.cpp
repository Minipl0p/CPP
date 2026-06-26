
#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

static void	printVector(const std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << (i + 1 < v.size() ? " " : "");
	std::cout << std::endl;
}

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int>	inputVector;
	if (!PmergeMe::parseInput(argc, argv, inputVector))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::deque<int>		inputDeque(inputVector.begin(), inputVector.end());

	std::cout << "Before: ";
	printVector(inputVector);

	// ---- vector ----
	clock_t	startVec = clock();
	PmergeMe::sortVector(inputVector);
	clock_t	endVec = clock();

	std::cout << "After:  ";
	printVector(inputVector);

	double	elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	// ---- deque ----
	clock_t	startDeq = clock();
	PmergeMe::sortDeque(inputDeque);
	clock_t	endDeq = clock();

	double	elapsedDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << inputVector.size()
			  << " elements with std::vector : " << elapsedVec << " us" << std::endl;
	std::cout << "Time to process a range of " << inputDeque.size()
			  << " elements with std::deque  : " << elapsedDeq << " us" << std::endl;

	return 0;
}
