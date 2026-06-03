
#pragma once

# include <iostream>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter {

    private:
        ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &src);

    public:
        static void convert(std::string str);
};
