/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:15:51 by miricci           #+#    #+#             */
/*   Updated: 2025/12/27 13:47:52 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout
			<< "index:" << Account::_accountIndex
			<< ";amount:" << Account::_amount
			<< ";created" << std::endl;
	return ;
}

Account::~Account( void ) {
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ) {
	
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	
	Account::_displayTimestamp();
	std::cout
			<< "accounts:" << Account::_nbAccounts
			<< ";total:" << Account::_totalAmount
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	
	Account::_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout
			<< ";deposits:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
	return ;	
}

bool	Account::makeWithdrawal( int withdrawal ) {
	
	Account::_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal) {
	
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const{
	
	return (Account::_totalAmount);
}

void	Account::displayStatus( void )const {
	
	Account::_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

void	Account::_displayTimestamp( void ) {

	time_t	t;
	tm	*ts;
	char timeStamp[16];
	
	time(&t);
	ts = gmtime(&t);
	strftime(timeStamp, 16, "%Y%m%d_%H%M%S", ts);
	std::cout << "[" << timeStamp << "] ";
}
