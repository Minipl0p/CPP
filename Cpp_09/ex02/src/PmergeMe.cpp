
#include "../includes/PmergeMe.hpp"
#include <cmath>
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

static void	buildFirstLevel(std::vector<t_node>& winners, std::vector<t_node>& losers,
							const std::vector<int>& input, bool& hasRemainder, int& remainder)
{
	hasRemainder = false;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
		{
			winners.push_back(std::make_pair(input[i], losers.size()));
			losers.push_back(std::make_pair(input[i + 1], losers.size()));
		}
		else
		{
			winners.push_back(std::make_pair(input[i + 1], losers.size()));
			losers.push_back(std::make_pair(input[i], losers.size()));
		}
	}

	if (input.size() % 2 != 0)
	{
		hasRemainder = true;
		remainder = input[input.size() - 1];
	}
}

static std::vector<t_node>	splitLevel(std::vector<t_node> winners, std::vector<t_node>& losers,
						const std::vector<t_node>& current, bool& hasRemainder, t_node& remainder)
{
	hasRemainder = false;

	for (size_t i = 0; i + 1 < current.size(); i += 2)
	{
		if (current[i].first > current[i + 1].first)
		{
			winners.push_back(std::make_pair(current[i].first, losers.size()));
			losers.push_back(std::make_pair(current[i + 1].first, losers.size()));
		}
		else
		{
			winners.push_back(std::make_pair(current[i + 1].first, losers.size()));
			losers.push_back(std::make_pair(current[i].first, losers.size()));
		}
	}

	if (current.size() % 2 != 0)
	{
		hasRemainder = true;
		remainder = current[current.size() - 1];
	}
	return winners;
}

static void	insertLoser(std::vector<t_node>& winners, t_node loser, t_node winnerRef)
{
	size_t insertPos = 0;

	while (insertPos < winners.size()
			&& winners[insertPos].first < winnerRef.first
			&& winners[insertPos].first < loser.first)
		++insertPos;

	winners.insert(winners.begin() + insertPos, loser);
}

static void	insertLosers(std::vector<t_node>& winners, const std::vector<t_node>& losers, const std::vector<int>& globalOrder)
{
	std::vector<t_node>	tmpWinners = winners;
	size_t				inserted = 0;

	for (size_t i = 0; i < globalOrder.size() && inserted < tmpWinners.size(); ++i) {
		if (globalOrder[i] >= (int)tmpWinners.size())
			continue;
		insertLoser(winners, losers[tmpWinners[globalOrder[i]].second], tmpWinners[globalOrder[i]]);
		++inserted;
	}
}

static void	insertRemainder(std::vector<t_node>& winners, t_node remainder)
{
	size_t insertPos = 0;

	while (insertPos < winners.size() && winners[insertPos].first < remainder.first)
		++insertPos;

	winners.insert(winners.begin() + insertPos, remainder);
}

static void	sortWinnersRec(std::vector<t_node>& current, std::vector<int> globalOrder)
{
	if (current.size() <= 1)
		return;

	std::vector<t_node> winners;
	std::vector<t_node> losers;
	bool hasRemainder = false;
	t_node remainder;

	std::vector<t_node> newWinner = splitLevel(winners, losers, current, hasRemainder, remainder);

	sortWinnersRec(winners, globalOrder);

	insertLosers(winners, losers, globalOrder);
	if (hasRemainder)
		insertRemainder(winners, remainder);

	current = winners;
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

	std::vector<t_node>	winners;
	std::vector<t_node>	losers;
	std::vector<int>	globalOrder;
	bool hasRemainder = false;
	int remainder = 0;

	globalOrderJacobsthal(globalOrder, input.size());

	buildFirstLevel(winners, losers, input, hasRemainder, remainder);

	sortWinnersRec(winners, globalOrder);

	insertLosers(winners, losers, globalOrder);

	if (hasRemainder)
		insertRemainder(winners, std::make_pair(remainder, -1));

	input.clear();
	for (size_t i = 0; i < winners.size(); ++i)
		input.push_back(winners[i].first);
}
