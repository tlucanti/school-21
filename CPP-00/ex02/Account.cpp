/*
* @Author: tlucanti
* @Date:   2021-11-12 17:30:27
* @Last Modified by:   tlucanti
* @Last Modified time: 2021-11-12 19:44:00
*/

#include "Account.hpp"

#include <iostream>
#include <sstream>

Account::Account(int initial_deposit)
{
	std::cout << "constructor for " << initial_deposit << std::endl;
}

Account::~Account()
{
	std::cout << "destructor" << std::endl;
}

int
Account::getNbAccounts()
{
	return _nbAccounts;
}

int
Account::getTotalAmount()
{
	return _totalAmount;
}

int
Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int
Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void
Account::displayAccountsInfos()
{
	std::cout << "displaying Account Infos" << std::endl;
}

void
Account::makeDeposit(int deposit)
{
	std::cout << "making deposit " << deposit << std::endl;
}

bool
Account::makeWithdrawal(int withdrawal)
{
	std::cout << "making withdrawal " << withdrawal << std::endl;
	return false;
}

int
Account::checkAmount() const
{
	return _amount;
}

void
Account::displayStatus() const
{
	std::cout << "displaying status" << std::endl;
}

void
Account::_displayTimestamp()
{
	std::cout << "[TIME_STAMP]" << std::endl;
}

Account::Account() {}

std::string
Account::index()

{
	std::stringstream ss("", std::ios_base::app);
	ss << "index: " << _accountIndex << ';'
	return ss.str();
}