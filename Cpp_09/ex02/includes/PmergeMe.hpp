
#pragma once

#include <deque>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>

class PmergeMe
{
	public:
		void sortVector(std::vector<int>& input, size_t groupSize);

	private:
		struct Block
		{
			std::vector<int> values;
			int              key;
			size_t           pairIndex;
			bool             isMain;
		};

		bool    hasFullPair(size_t start, size_t groupSize, size_t size) const;
		void    orderPairs(std::vector<int>& input, size_t groupSize);

		Block   makeBlock(const std::vector<int>& input,
				size_t start,
				size_t groupSize,
				size_t pairIndex,
				bool isMain) const;

		void    buildChains(const std::vector<int>& input,
				size_t groupSize,
				std::vector<Block>& mainChain,
				std::vector<Block>& pending,
				std::vector<int>& remainder) const;

		std::vector<size_t> buildJacobsthalOrder(size_t pendingCount) const;
		std::vector<size_t> buildJacobsthalSequence(size_t maxValue) const;

		size_t  findPartnerPosition(const std::vector<Block>& mainChain,
				size_t pairIndex) const;

		size_t  findInsertionPosition(const std::vector<Block>& mainChain,
				const Block& pendingBlock,
				size_t partnerPos) const;

		void    insertBlockIntoChain(std::vector<Block>& mainChain,
				const Block& block,
				size_t insertPos) const;

		void    insertionPhase(std::vector<int>& input, size_t groupSize);
		void    rebuildInputFromChain(std::vector<int>& input,
				const std::vector<Block>& mainChain,
				const std::vector<int>& remainder) const;
};

