#include <cctype>
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < ac; i++)
	{
		std::string str = static_cast<std::string>(av[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			std::cout << static_cast<char>(std::toupper(*it));
	}
	std::cout << std::endl;
}
