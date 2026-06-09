
#include "../includes/RPN.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>

RPN::RPN(void): _stack() {}

RPN::~RPN(void) {}

RPN::RPN(const RPN &cpy) { *this = cpy; }

RPN	&RPN::operator=(const RPN &src)
{
    if (this == &src)
		return *this;
	_stack = src._stack;
	return *this;
}

static bool	isOperator(char a)
{
	return (a == '+' || a == '-' || a == '*' || a == '/');
}

static std::pair<int, int>	storeNumberAndPopStack(std::stack<int> &stack)
{
	std::pair<int, int> nb;
	nb.second = stack.top();
	stack.pop();
	nb.first = stack.top();
	stack.pop();
	return nb;
}

static void	calculateAndPushOnStack(std::stack<int> &stack, std::pair<int, int> nb, strIt it)
{
	if (*it == '+')
		stack.push(nb.first + nb.second);
	if (*it == '-')
		stack.push(nb.first - nb.second);
	if (*it == '*')
		stack.push(nb.first * nb.second);
	if (*it == '/') {
		if (nb.second == 0)
			throw std::runtime_error("Division by 0 is impossible !");
		stack.push(nb.first / nb.second);
	}
}

std::string RPN::solveRPN(std::string calc)
{

	for (strIt it = calc.begin(); it != calc.end(); it++) {
		if (std::isspace(*it))
			continue;
		if (std::isdigit(*it)) {
			_stack.push(*it - '0');
			continue;
		}

		if (isOperator(*it)) {
			if (_stack.size() <= 1)
				throw std::runtime_error("Error");
			std::pair<int, int> nb = storeNumberAndPopStack(_stack);
			calculateAndPushOnStack(_stack, nb, it);
		}
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	std::stringstream oss;
	oss << _stack.top();
	std::string str = oss.str();
	return str;
}
