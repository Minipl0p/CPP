#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int		Account::getTotalAmount( void )
{
	return _totalAmount;
}

int		Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts << ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_totalNbDeposits += 0;
	_totalNbWithdrawals += 0;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";p_amount:" << this->_amount
				<< ";deposit:" << deposit << std::flush;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout	<< ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << std::flush;
	if (withdrawal > this->_amount)
	{
		std::cout	<< "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout	<< withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
				<< this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm* ptm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", ptm);
    std::cout << buffer << std::flush;
}
