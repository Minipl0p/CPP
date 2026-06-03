
#include "../includes/iter.hpp"
#include <iostream>

#define GRAY  "\033[90m"
#define RED   "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
void doubler(T &value) {
    value *= 2;
}

template <typename T>
void printTest(const std::string &input,
               const std::string &eResult,
               T *arr, size_t len, void (*func)(T &))
{
    std::cout << GRAY << input << RESET << std::endl;
    std::cout << GRAY "attendu: " RED << eResult << RESET << std::endl;
    std::cout << RED;
    iter(arr, len, func);
    std::cout << RESET << std::endl << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arr[] = {argv[1]};
        iter(arr, 1, print_elem<std::string>);
        return 0;
    }
    if (argc != 1)
        return 0;

    int   ints[]   = {1, 2, 3, 4, 5};
    float floats[] = {1.1f, 2.2f, 3.3f};
    char  chars[]  = {'a', 'b', 'c'};
    int   dubs[]   = {10, 20, 30};

    printTest("iter sur int {1,2,3,4,5} -> print",
              "1 2 3 4 5",
              ints, 5, print_elem<int>);

    printTest("iter sur float {1.1, 2.2, 3.3} -> print",
              "1.1 2.2 3.3",
              floats, 3, print_elem<float>);

    printTest("iter sur char {a, b, c} -> print",
              "a b c",
              chars, 3, print_elem<char>);

    iter(dubs, 3, doubler<int>);
    printTest("iter sur int {10,20,30} -> doubler puis print",
              "20 40 60",
              dubs, 3, print_elem<int>);

    return 0;
}
