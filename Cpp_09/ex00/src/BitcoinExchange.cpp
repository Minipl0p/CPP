
#include "../includes/BitcoinExchange.hpp"
#include <climits>
#include <cmath>
#include <fstream>
#include <map>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool isValidDate(const std::string &str)
{
	if (str.length() != 10 || str[4] != '-' || str[7] != '-') {
		std::cout << "Error: bad input => " << str << std::endl;
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(str[i])) {
			std::cout << "Error: bad input => " << str << std::endl;
			return false;
		}
	}

	int year  = std::strtol(str.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(str.substr(5, 2).c_str(), NULL, 10);
	int day   = std::strtol(str.substr(8, 2).c_str(), NULL, 10);

	if (month < 1 || month > 12) {
		std::cout << "Error: bad input => " << str << std::endl;
		return false;
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1]){
		std::cout << "Error: bad input => " << str << std::endl;
		return false;
	}
	return true;
}

bool	isValidValue(double value)
{
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > INT_MAX) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange(const std::string &file)
{

	if (file.size() < 4 || file.substr(file.size() - 4) != ".csv")
		throw std::runtime_error("Error: file must be a .csv");

	std::ifstream data(file.c_str());
	if (!data.is_open())
		throw std::runtime_error("Could'nt open the data file.");

	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		size_t	comma = line.find(',', 0);
		if (comma == std::string::npos)
			continue;

		std::string	valueStr = line.substr(comma + 1, line.length() - comma);
		char		*end;
		double		value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0')
			continue;

		std::string	date = line.substr(0, comma);
		if (!isValidDate(date) || !isValidValue(value))
			continue;
		_database[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	_database = cpy._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_database = src._database;
	return *this;
}

double	BitcoinExchange::getValue(const std::string &key) const
{
	if (_database.empty() || key < _database.begin()->first) {
		std::cout << "Error : Date too old !\n" << std::flush;
		return NAN;
	}
	std::map<std::string, double>::const_iterator it = _database.upper_bound(key);
	it--;
	return it->second;
}

void	BitcoinExchange::analyseInput(const std::string &file)
{
	std::ifstream data(file.c_str());
	if (!data.is_open())
		throw std::runtime_error("Could'nt open the file.");

	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		size_t	separator = line.find('|', 0);
		if (separator == std::string::npos) {
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, separator);
		while (!date.empty() && std::isspace(date[date.size() - 1]))
			date.erase(date.size() - 1);
		if (!isValidDate(date))
			continue;

		std::string	valueStr = line.substr(separator + 1, line.length() - separator);
		char		*end;
		double		value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0') {
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		if (value <= 0) {
			std::cout << "Error : not a positive number." << std::endl;
			continue;
		}
		if (value >= INT_MAX) {
			std::cout << "Error : too large number." << std::endl;
			continue;
		}
		double		change = getValue(date);
		if (std::isnan(change)) {
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << change * value << std::endl;
	}
}
