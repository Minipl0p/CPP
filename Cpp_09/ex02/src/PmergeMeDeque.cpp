
#include "../includes/PmergeMe.hpp"
#include <cmath>
#include <vector>

static void	splitMainAndPend(const std::deque<int>& mainChain, int groupSize, std::deque<int>& main,
							std::deque<int>& pend, std::deque<size_t>& winnerPos, std::deque<int>& leftover)
{
	size_t	n			= mainChain.size();
	size_t	pairCount	= n / (groupSize * 2);
	bool	hasLeftover	= (n % (groupSize * 2)) != 0;

	for (size_t i = 0; i < pairCount; i++) {
		size_t	loserStart	= 2 * i * groupSize;
		size_t	winnerStart	= (2 * i + 1) * groupSize;
		size_t	winnerEnd	= (2 * i + 2) * groupSize;

		pend.insert(pend.end(), mainChain.begin() + loserStart, mainChain.begin() + winnerStart);
		main.insert(main.end(), mainChain.begin() + winnerStart, mainChain.begin() + winnerEnd);
		winnerPos.push_back(i + 1);
	}

	if (hasLeftover) {
		size_t	leftoverStart = pairCount * 2 * groupSize;
		leftover.assign(mainChain.begin() + leftoverStart, mainChain.end());
	}
}

static size_t	binarySearchBlock(const std::deque<int>& main, int groupSize, int target, size_t hi)
{
	size_t	lo = 0;

	while (lo < hi) {
		size_t	mid		= lo + (hi - lo) / 2;
		int		midRep	= main[(mid + 1) * groupSize - 1];

		if (midRep < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

static void	swapBlockPairs(std::deque<int>& mainChain, int groupSize)
{
	size_t	n			= mainChain.size();
	size_t	pairCount	= n / (groupSize * 2);

	for (size_t i = 0; i < pairCount; i++) {
		size_t	leftStart	= 2 * i * groupSize;
		size_t	rightStart	= (2 * i + 1) * groupSize;
		size_t	leftIdx		= rightStart - 1;
		size_t	rightIdx	= (2 * i + 2) * groupSize - 1;

		if (mainChain[leftIdx] > mainChain[rightIdx])
			std::swap_ranges(mainChain.begin() + leftStart, mainChain.begin() + rightStart, mainChain.begin() + rightStart);
	}
}

static void	sortdequeRec(std::deque<int>& mainChain, int groupSize, const std::deque<size_t>& insertOrder)
{
	std::deque<int>	main;
	std::deque<int>	pend;
	std::deque<size_t>	winnerPos;
	std::deque<int>	leftover;

	// ---------- Base case ----------
	if (static_cast<size_t>(groupSize) * 2 > mainChain.size())
		return;

	// ---------- 1. Swap blocs ----------
	swapBlockPairs(mainChain, groupSize);

	// ---------- 2. Recursion ----------
	sortdequeRec(mainChain, groupSize * 2, insertOrder);

	// ---------- 3. Split : fill main, pend, winnerPos, leftover ----------
	splitMainAndPend(mainChain, groupSize, main, pend, winnerPos, leftover);

	// ---------- 4. Free insertion ----------
	main.insert(main.begin(), pend.begin(), pend.begin() + groupSize);

	// ---------- 5. Insert pend[1..] ----------
	size_t	pendBlockCount = pend.size() / groupSize;

	for (size_t i = 0; i < insertOrder.size(); i++) {
		size_t	idx = insertOrder[i];
		if (idx >= pendBlockCount)
			continue;

		int		loserRep	= pend[(idx + 1) * groupSize - 1];
		size_t	hi			= winnerPos[idx];
		size_t	pos			= binarySearchBlock(main, groupSize, loserRep, hi);

		main.insert(main.begin() + pos * groupSize, pend.begin() + idx * groupSize, pend.begin() + (idx + 1) * groupSize);

		for (size_t k = 0; k < winnerPos.size(); k++) {
			if (winnerPos[k] >= pos)
				winnerPos[k] += 1;
		}
	}

	// ---------- 6. Insertion of leftover if groupSize == 1) ----------
	size_t	leftoverBlocks	= leftover.size() / groupSize;
	size_t	residueSize		= leftover.size() % groupSize;

	for (size_t b = 0; b < leftoverBlocks; b++)
	{
		int		blockRep	= leftover[(b + 1) * groupSize - 1];
		size_t	nbBlocks	= main.size() / groupSize;
		size_t	pos			= binarySearchBlock(main, groupSize, blockRep, nbBlocks);

		main.insert(main.begin() + pos * groupSize,
				leftover.begin() + b * groupSize,
				leftover.begin() + (b + 1) * groupSize);
	}

	// ---------- 7. Rebuild mainChain ----------
	if (residueSize > 0)
		main.insert(main.end(), leftover.begin() + leftoverBlocks * groupSize, leftover.end());
	mainChain.swap(main);
}

static void	globalOrderJacobsthal(std::deque<size_t>& globalOrder, int max)
{
	if (max <= 0)
		return;

	std::deque<int>	jacob;
	jacob.push_back(1);

	int	prev2 = 0;
	int	prev1 = 1;

	while (true)
	{
		int	current = prev1 + (2 * prev2);
		if (current > max)
			break;
		if (current != jacob.back())
			jacob.push_back(current);
		prev2 = prev1;
		prev1 = current;
	}

	int	previous = 1;

	for (size_t i = 1; i < jacob.size(); ++i)
	{
		int	current = jacob[i];

		for (int index = current; index > previous; --index)
			globalOrder.push_back(index - 1);
		previous = current;
	}
	for (int index = max; index > previous; --index)
		globalOrder.push_back(index - 1);
}

void	PmergeMe::sortDeque(std::deque<int>& input)
{
	if (input.size() <= 1)
		return;

	std::deque<size_t>	globalOrder;

	globalOrderJacobsthal(globalOrder, input.size());

	sortdequeRec(input, 1, globalOrder);
}
