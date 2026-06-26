
#include "../includes/PmergeMe.hpp"
#include <cmath>
#include <utility>
#include <vector>

bool	PmergeMe::isPositiveInteger(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	PmergeMe::toInt(const std::string& str, int& value)
{
	std::istringstream iss(str);
	long tmp;

	iss >> tmp;
	if (iss.fail() || !iss.eof())
		return false;
	if (tmp < 0 || tmp > INT_MAX)
		return false;
	value = static_cast<int>(tmp);
	return true;
}

bool	PmergeMe::parseInput(int argc, char** argv, std::vector<int>& input)
{
	input.clear();
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		int value;

		if (!isPositiveInteger(str))
			return false;
		if (!toInt(str, value))
			return false;
		input.push_back(value);
	}
	return true;
}

static void splitMainAndPend( const std::vector<int>& mainChain, int groupSize, std::vector<int>& main,
							std::vector<int>& pend, std::vector<size_t>& winnerPos, std::vector<int>& leftover)
{
	size_t	n			= mainChain.size();
	size_t	pairCount	= n / (groupSize * 2);
	bool	hasLeftover	= (n % (groupSize * 2)) != 0;

	for (size_t i = 0; i < pairCount; i++)
	{
		size_t	loserStart	= 2 * i * groupSize;
		size_t	winnerStart	= (2 * i + 1) * groupSize;
		size_t	winnerEnd	= (2 * i + 2) * groupSize;

		std::vector<int>	loserBlock( mainChain.begin() + loserStart, mainChain.begin() + winnerStart);
		std::vector<int>	winnerBlock( mainChain.begin() + winnerStart, mainChain.begin() + winnerEnd);

		pend.insert(pend.end(), mainChain.begin() + loserStart, mainChain.begin() + winnerStart);
        main.insert(main.end(), mainChain.begin() + winnerStart, mainChain.begin() + winnerEnd);
        winnerPos.push_back(i);
	}

	if (hasLeftover)
	{
		size_t leftoverStart = pairCount * 2 * groupSize;
		leftover.assign(mainChain.begin() + leftoverStart, mainChain.end());
	}
}

static void swapBlockPairs(std::vector<int>& mainChain, int groupSize)
{
	size_t	n = mainChain.size();
	size_t	pairCount = n / (groupSize * 2);

	for (size_t i = 0; i < pairCount; i++) {
		size_t leftStart  = 2 * i * groupSize;
		size_t rightStart = (2 * i + 1) * groupSize;
		size_t leftIdx = rightStart - 1;
		size_t rightIdx = (2 * i + 2) * groupSize - 1;

		if (mainChain[leftIdx] > mainChain[rightIdx])
			std::swap_ranges( mainChain.begin() + leftStart, mainChain.begin() + rightStart, mainChain.begin() + rightStart);
	}
}

static void sortVectorRec(std::vector<int>& mainChain, int groupSize, std::vector<size_t> insertOrder)
{
    std::vector<int>	main;
    std::vector<int>	pend;
    std::vector<size_t>	winnerPos;
    std::vector<int>	leftover;

    // ---------- Base case ----------
	if (groupSize * 2 > mainChain.size())
		return;

    // ---------- 1. Swap par paires de blocs ----------
	swapBlockPairs(mainChain, groupSize);

    // ---------- 2. Récursion ----------
    sortVectorRec(mainChain, groupSize * 2, insertOrder);

    // ---------- 3. Split : remplir main, pend, winnerPos, leftover ----------
	splitMainAndPend(mainChain, groupSize, main, pend, winnerPos, leftover);

    // ---------- 4. Insertion gratuite de b1 ----------
    // main.insert(begin, pend[0])
    // incrémenter tous les winnerPos de 1

    // ---------- 5. Construire l'ordre Jacobsthal puis insérer pend[1..] ----------
    // insertOrder = buildJacobsthalOrder(pend.size())
    // pour chaque idx dans insertOrder :
    //     upperBound = winnerPos[idx]
    //     pos        = binarySearch(main, pend[idx], 0, upperBound)
    //     main.insert(pos, pend[idx])
    //     mettre à jour tous les winnerPos[k] >= pos en +1

    // ---------- 6. Insertion du leftover ----------
    // si hasLeftover :
    //     pos = binarySearch(main, leftover, 0, main.size())
    //     main.insert(pos, leftover)

    // ---------- 7. Reconstruire mainChain ----------
    // mainChain.clear()
    // pour chaque bloc dans main :
    //     mainChain.insert(end, bloc.begin(), bloc.end())
}

static void	globalOrderJacobsthal(std::vector<int>& globalOrder, int max)
{
	if (max <= 0)
		return;

	std::vector<int> jacob;
	jacob.push_back(1);

	int prev2 = 0;
	int prev1 = 1;

	while (true)
	{
		int current = prev1 + (2 * prev2);
		if (current > max)
			break;
		if (current != jacob.back())
			jacob.push_back(current);
		prev2 = prev1;
		prev1 = current;
	}

	globalOrder.push_back(0);

	int previous = 1;

	for (size_t i = 1; i < jacob.size(); ++i)
	{
		int current = jacob[i];

		for (int index = current; index > previous; --index)
			globalOrder.push_back(index - 1);
		previous = current;
	}
	for (int index = max; index > previous; --index)
		globalOrder.push_back(index - 1);
}

void	PmergeMe::sortVector(std::vector<int>& input)
{
	if (input.size() <= 1)
		return;

	std::vector<int>	globalOrder;

	globalOrderJacobsthal(globalOrder, input.size());

	sortVectorRec(input, 1);
}
