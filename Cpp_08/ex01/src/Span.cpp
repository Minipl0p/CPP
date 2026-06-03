
#include "../includes/Span.hpp"

Span::Span(): _capacity(0), _N() {}
Span::Span(unsigned int N): _capacity(N), _N() {}
Span::~Span() {}
Span::Span(const Span &src): _capacity(src._capacity), _N()
{ _N = src._N; }
Span	Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	_capacity = src._capacity;
	_N.resize(_capacity);
	_N = src._N;
	return *this;
}

void	Span::addNumber(unsigned int N)
void	Span::shortestSpan()
void	Span::longestSpan()
