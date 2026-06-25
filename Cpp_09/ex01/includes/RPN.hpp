
#pragma once

# include <stack>
# include <string>

class RPN {

    private:
        std::stack<int> _stack;
    public:
        ~RPN(void);
		RPN(void);
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &src);

        std::string solveRPN(std::string calc);
};

typedef std::string::iterator strIt;
