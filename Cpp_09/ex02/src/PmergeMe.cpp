
#include "../includes/PmergeMe.hpp"

bool PmergeMe::hasFullPair(size_t start, size_t groupSize, size_t size) const
{
	size_t totalBlock = groupSize * 2;
	return (start + totalBlock <= size);
}

void PmergeMe::orderPairs(std::vector<int>& input, size_t groupSize)
{
	size_t totalBlock = groupSize * 2;
	size_t usableSize = (input.size() / totalBlock) * totalBlock;

	for (size_t start = 0; start < usableSize; start += totalBlock)
	{
		if (input[start] > input[start + groupSize])
			for (size_t i = 0; i < groupSize; ++i)
				std::swap(input[start + i], input[start + groupSize + i]);
	}
}

PmergeMe::Block PmergeMe::makeBlock(const std::vector<int>& input, size_t start, size_t groupSize,
									size_t pairIndex, bool isMain) const
{
	Block block;

	block.key = input[start];
	block.pairIndex = pairIndex;
	block.isMain = isMain;

	for (size_t i = 0; i < groupSize; ++i)
		block.values.push_back(input[start + i]);

	return block;
}

void PmergeMe::buildChains(const std::vector<int>& input, size_t groupSize,
							std::vector<Block>& mainChain, std::vector<Block>& pending,
							std::vector<int>& remainder) const
{
	size_t totalBlock = groupSize * 2;
	size_t usableSize = (input.size() / totalBlock) * totalBlock;
	size_t pairIndex = 0;

	for (size_t start = 0; start < usableSize; start += totalBlock)
	{
		Block leftBlock = makeBlock(input, start, groupSize, pairIndex, false);
		Block rightBlock = makeBlock(input, start + groupSize, groupSize, pairIndex, true);

		pending.push_back(leftBlock);
		mainChain.push_back(rightBlock);
		++pairIndex;
	}

	for (size_t i = usableSize; i < input.size(); ++i)
		remainder.push_back(input[i]);
}

std::vector<size_t> PmergeMe::buildJacobsthalSequence(size_t maxValue) const
{
	std::vector<size_t> sequence;

	if (maxValue == 0)
		return sequence;

	sequence.push_back(1);

	size_t prev2 = 0;
	size_t prev1 = 1;

	while (true)
	{
		size_t current = prev1 + (2 * prev2);

		if (current > maxValue)
			break;
		if (current != sequence.back())
			sequence.push_back(current);

		prev2 = prev1;
		prev1 = current;
	}

	return sequence;
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t pendingCount) const
{
	std::vector<size_t> order;

	if (pendingCount <= 1)
		return order;

	std::vector<bool> used(pendingCount, false);
	used[0] = true;

	std::vector<size_t> jacob = buildJacobsthalSequence(pendingCount);
	size_t previous = 1;

	for (size_t j = 1; j < jacob.size(); ++j)
	{
		size_t current = jacob[j];
		size_t index = current;

		while (index > previous)
		{
			if (index - 1 < pendingCount && !used[index - 1])
			{
				order.push_back(index - 1);
				used[index - 1] = true;
			}
			--index;
		}
		previous = current;
	}

	for (size_t index = pendingCount; index > previous; --index)
	{
		if (index - 1 < pendingCount && !used[index - 1])
		{
			order.push_back(index - 1);
			used[index - 1] = true;
		}
	}

	return order;
}

size_t PmergeMe::findPartnerPosition(const std::vector<Block>& mainChain, size_t pairIndex) const
{
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		if (mainChain[i].pairIndex == pairIndex && mainChain[i].isMain)
			return i;
	}
	return mainChain.size();
}

size_t PmergeMe::findInsertionPosition(const std::vector<Block>& mainChain,
									   const Block& pendingBlock,
									   size_t partnerPos) const
{
	size_t pos = 0;

	while (pos < partnerPos)
	{
		if (pendingBlock.key < mainChain[pos].key)
			break;
		++pos;
	}
	return pos;
}

void PmergeMe::insertBlockIntoChain(std::vector<Block>& mainChain,
									const Block& block,
									size_t insertPos) const
{
	mainChain.insert(mainChain.begin() + insertPos, block);
}

void PmergeMe::rebuildInputFromChain(std::vector<int>& input,
									 const std::vector<Block>& mainChain,
									 const std::vector<int>& remainder) const
{
	input.clear();

	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < mainChain[i].values.size(); ++j)
			input.push_back(mainChain[i].values[j]);
	}

	for (size_t i = 0; i < remainder.size(); ++i)
		input.push_back(remainder[i]);
}

void PmergeMe::insertionPhase(std::vector<int>& input, size_t groupSize)
{
	std::vector<Block> mainChain;
	std::vector<Block> pending;
	std::vector<int> remainder;

	buildChains(input, groupSize, mainChain, pending, remainder);

	if (mainChain.empty())
		return;

	if (!pending.empty())
		mainChain.insert(mainChain.begin(), pending[0]);

	std::vector<size_t> order = buildJacobsthalOrder(pending.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pendingIndex = order[i];
		const Block& currentPending = pending[pendingIndex];

		size_t partnerPos = findPartnerPosition(mainChain, currentPending.pairIndex);
		size_t insertPos = findInsertionPosition(mainChain, currentPending, partnerPos);

		insertBlockIntoChain(mainChain, currentPending, insertPos);
	}

	rebuildInputFromChain(input, mainChain, remainder);
}

void PmergeMe::sortVector(std::vector<int>& input, size_t groupSize)
{
	if (groupSize == 0 || groupSize >= input.size())
		return;

	orderPairs(input, groupSize);
	sortVector(input, groupSize * 2);
	insertionPhase(input, groupSize);
}
