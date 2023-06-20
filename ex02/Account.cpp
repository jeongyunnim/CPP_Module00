#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << \
				";deposits:" <<  getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
	:	_accountIndex(_nbAccounts)
	,	_amount(initial_deposit)
	,	_nbDeposits(0)
	,	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:";
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (checkAmount() - withdrawal >= 0)
	{
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:";
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << \
				";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	timer;
	struct tm *t;
	
	timer = time(NULL);
	t = localtime(&timer);

	std::cout << '[' << 1900 + t->tm_year << \
				std::setw(2) << std::setfill('0') << t->tm_mon << \
				std::setw(2) << std::setfill('0') << t->tm_hour << \
				'_' << \
				std::setw(2) << std::setfill('0') << t->tm_hour << \
				std::setw(2) << std::setfill('0') << t->tm_min << \
				std::setw(2) << std::setfill('0') << t->tm_sec << ']';
	}