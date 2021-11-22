/*
* @Author: tlucanti
* @Date:   2021-11-12 17:30:27
* @Last Modified by:   tlucanti
* @Last Modified time: 2021-11-12 19:44:00
*/

#include "Account.hpp"

namespace tlucanti
{
	template <typename type_t>
	std::string to_string(const type_t &x)
	{
		return static_cast<std::ostringstream &>((
			std::ostringstream() << std::dec << x)).str();
	}
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
		_nbWithdrawals(0), _last_deposit(0), _last_withdrawal(0)
{
	_totalAmount += initial_deposit;
	std::cout << time() << index() << amount() << "created;\n";
}

Account::~Account()
{
	--_nbAccounts;
	std::cout << time() << index() << amount() << "closed;\n";
}

__UNUSED int
Account::getNbAccounts()
{
	std::cout << "getNbAccounts\n";
	return _nbAccounts;
}

__UNUSED int
Account::getTotalAmount()
{
	std::cout << "getTotalAmount\n";
	return _totalAmount;
}

__UNUSED int
Account::getNbDeposits()
{
	std::cout << "getNbDeposits\n";
	return _totalNbDeposits;
}

__UNUSED int
Account::getNbWithdrawals()
{
	std::cout << "getNbWithdrawals\n";
	return _totalNbWithdrawals;
}

void
Account::displayAccountsInfos()
{
	std::cout << time() << accounts() << total() << total_deposits()
		<< total_withdrawals() << std::endl;
}

void
Account::makeDeposit(int _deposit)
{
	++_totalNbDeposits;
	++_nbDeposits;
	_last_deposit = _deposit;
	_amount += _deposit;
	_totalAmount += _deposit;
	std::cout << index() << p_amount() << deposit() << amount() << nb_deposits()
		<< std::endl;
}

bool
Account::makeWithdrawal(int _withdrawal)
{
	_last_withdrawal = _withdrawal;
	std::cout << time() << index() << amount() << withdrawal() << std::endl;
	if (_amount < _withdrawal)
		return false;
	_amount -= _withdrawal;
	_totalAmount -= _withdrawal;
	++_totalNbWithdrawals;
	std::cout << amount() << nb_withdrawals() << std::endl;
	return true;
}

__UNUSED int
Account::checkAmount() const
{
	return _amount;
}

void
Account::displayStatus() const
{
	std::cout << time() << index() << deposits() << withdrawals() << std::endl;
}

__UNUSED void
Account::_displayTimestamp()
{
	std::cout << time();
}

std::string
Account::time()
{
	return "[TIME_STAMP] ";
}

std::string
Account::index() const

{
	return "index:" + tlucanti::to_string(_accountIndex) + ';';
}

std::string
Account::amount() const
{
	return "amount:" + tlucanti::to_string(_amount) + ';';
}

std::string
Account::total()
{
	return "total:" + tlucanti::to_string(_totalAmount) + ';';
}

std::string
Account::deposits() const
{
	return "deposits:" + tlucanti::to_string(_nbWithdrawals) + ';';
}

std::string
Account::withdrawals()
{
	return "withdrawals:" + tlucanti::to_string(_totalNbWithdrawals) + ';';
}

std::string
Account::total_deposits()
{
	return "deposits:" + tlucanti::to_string(_totalNbDeposits) + ';';
}

std::string
Account::total_withdrawals()
{
	return "withdrawals:" + tlucanti::to_string(_totalNbWithdrawals) + ';';
}

std::string
Account::p_amount() const
{
	return amount();
}

std::string
Account::nb_deposits() const
{
	return "nb_deposits:" + tlucanti::to_string(_nbDeposits) + ';';
}

std::string
Account::nb_withdrawals() const
{
	return "nb_withdrawals:" + tlucanti::to_string(_nbWithdrawals) + ';';
}

std::string
Account::accounts()
{
	return "accounts:" + tlucanti::to_string(_nbAccounts) + ';';
}

std::string
Account::deposit() const
{
	return "deposit:" + tlucanti::to_string(_last_deposit) + ';';
}

std::string
Account::withdrawal() const
{
	if (_amount < _last_withdrawal)
		return "withdrawal:refused\n";
	return "withdrawal:" + tlucanti::to_string(_last_withdrawal);
}

#if __cplusplus <= 199711L
	__UNUSED Account::Account()
		: _accountIndex(0), _amount(0), _nbDeposits(0),
		  _nbWithdrawals(0), _last_deposit(0), _last_withdrawal(0)
	{}
#else
	Account::Account() = default;
#endif