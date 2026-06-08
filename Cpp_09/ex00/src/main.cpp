
#include "../includes/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2 || ac >= 3)
    {
        std::cerr << "Wrong parameter number"<< std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc("data.csv");
        btc.analyseInput(av[1]);
    }
    catch(const std::exception &e) { std::cerr << e.what() << '\n'; }
    return 0;
}
