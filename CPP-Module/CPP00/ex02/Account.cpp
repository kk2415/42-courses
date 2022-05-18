#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
	_nbAccounts--;
	_totalNbDeposits--;
	_totalNbWithdrawals--;
	_totalAmount -= _amount;
}

Account::Account( void )
{
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
	_nbAccounts++;
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
			<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::string	min;
	time_t		valTime;
	struct tm*	pTimeInfo;

	time(&valTime);
	pTimeInfo = localtime(&valTime);
	min = std::to_string(pTimeInfo->tm_min);
	if (pTimeInfo->tm_min < 10)
		min = "0" + std::to_string(pTimeInfo->tm_min);
	std::cout << "[" << pTimeInfo->tm_year + 1900 << pTimeInfo->tm_mon + 1 << pTimeInfo->tm_mday <<
		"_" << pTimeInfo->tm_hour << min << pTimeInfo->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "deposit:" << deposit << ";" << "amount:" << _amount + deposit << ";" << "nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if ((_amount - withdrawal) < 0)
	{
		std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "index:" << _accountIndex << ";" << "p_amount:"
		<< _amount << ";" << "withdrawal:" << withdrawal << ";" << "amount:"
			<< _amount - withdrawal << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}
