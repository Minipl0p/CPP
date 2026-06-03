
#pragma once

#include <vector>

class Span {
	private:
		std::vector<int>	_N;
		unsigned int		_capacity;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span	operator=(const Span &src);

		void	addNumber(unsigned int N);
		void	addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
};
