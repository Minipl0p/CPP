
#pragma once

#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cctype>

class PmergeMe
{
	public:
		static bool	parseInput(int argc, char** argv, std::vector<int>& input);
		static void	sortVector(std::vector<int>& input);

	private:
		static bool	isPositiveInteger(const std::string& str);
		static bool	toInt(const std::string& str, int& value);
};

typedef std::pair<int, int> t_node;
