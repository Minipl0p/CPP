
#pragma once

class ScalarConverter {

    private:
        ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &src);

    public:
        static void convert(std::string str);
};
