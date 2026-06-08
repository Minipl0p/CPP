
#pragma once

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_database;
		double	getValue(const std::string &key) const;
		BitcoinExchange();
	public:
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange(const std::string &file);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void	analyseInput(const std::string &file);
};
