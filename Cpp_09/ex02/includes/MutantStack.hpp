
#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

    private:

    public:
        MutantStack(): std::stack<T>() {};
		~MutantStack() {};
		MutantStack(const MutantStack &cpy): std::stack<T>(cpy) {};
        MutantStack &operator=(const MutantStack &src)
		{
			if (this == &src)
				return *this;
			std::stack<T>::operator=(src);
			return *this;
		};

		typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin()
		{
			return(std::stack<T>::c.begin());
		};
		const_iterator begin() const
		{
			return(std::stack<T>::c.begin());
		};
        iterator end()
		{
			return(std::stack<T>::c.end());
		};
		const_iterator end() const
		{
			return(std::stack<T>::c.end());
		};
};
