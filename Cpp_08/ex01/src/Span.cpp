
#include "../includes/Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span():_N(), _capacity(0) {}
Span::Span(unsigned int N): _N(), _capacity(N) {}
Span::~Span() {}
Span::Span(const Span &src):_N(src._N), _capacity(src._capacity) {}
Span	Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	_capacity = src._capacity;
	_N = src._N;
	return *this;
}

void	Span::addNumber(unsigned int N)
{
	if (_N.size() >= _capacity)
		throw std::length_error("Span is full");
	_N.push_back(N);
}

void	Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_N.size() + std::distance(begin, end) > this->_capacity)
		throw std::logic_error("Not Enough Elements");
	this->_N.insert(this->_N.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_N.size() <= 1)
		throw std::logic_error("Not Enough Elements");
	std::vector<int> tmp = this->_N;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		int tmp2 = tmp[i] - tmp[i - 1];
		if (tmp2 < min)
			min = tmp2;
	}
	return min;
}

int	Span::longestSpan()
{
	if (_N.size() <= 1)
		throw std::logic_error("Not Enough Elements");
	return *std::max_element(_N.begin(), _N.end()) - *std::min_element(_N.begin(), _N.end());
}
