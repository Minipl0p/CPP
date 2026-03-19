#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	// PARSE
	if (ac != 4)
	{
		std::cout	<< "Invalid number of arguments\n" << std::flush;
		return 1;
	}

	// OPEN THE FILE
	std::fstream infile;
	infile.open(av[1]);
	if (!infile.is_open())
	{
		std::cout	<< av[1] << " is not a file or access denied" << std::endl;
		return 1;
	}

	// CREATE THE FILE.REPLACE
	std::string	outfile = std::string(av[1]) + ".replace";
	std::ofstream replaceFile(outfile.c_str());
	if (!replaceFile.is_open())
	{
		std::cout	<<"Cannot create output file !" << std::endl;
		infile.close();
		return	1;
	}

	// READ, SEARCH AND REPLACE
	std::string	line;
	std::string	toFind = av[2];

	while (std::getline(infile, line))
	{
		size_t	pos = 0;
		size_t	lastPos = 0;

		while ((pos = line.find(toFind, lastPos)) != std::string::npos)
		{
			replaceFile	<< line.substr(lastPos, pos - lastPos);
			replaceFile	<< av[3];
			lastPos = pos + toFind.length();
		}
		replaceFile	<< line.substr(lastPos) << "\n";
	}

	infile.close();
	replaceFile.close();
	return 0;
}
