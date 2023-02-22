/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:50:39 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/08 18:23:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;
/**========================================================================
 *                           Accessors
 *========================================================================**/
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

/**========================================================================
 *                           De/Constructor
 *========================================================================**/
Account::Account(int initial_deposit) 
{
 	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
	return ;
}

Account::~Account( void )
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
	return ;
}
/**========================================================================
 *                           Transactions and Checks
 *========================================================================**/

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			<< "total:" << getTotalAmount() << ';'
			<< "deposits:" << getNbDeposits() << ';'
			<< "withdrawals:" << getNbWithdrawals()
			<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "deposit:" << deposit << ';';
	_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
	_amount += deposit;
	std::cout<< "amount:" << _amount << ';'
		<< "nb_deposits:" << _nbDeposits << 
		std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:";
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";";
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

/**========================================================================
 *                           Utils
 *========================================================================**/
 
void Account::_displayTimestamp(void)
{
	time_t timestamp = std::time(nullptr);

	std::cout<<'['<<std::put_time(std::localtime(&timestamp), "%Y%m%d_%H%M%S") <<"] ";
}