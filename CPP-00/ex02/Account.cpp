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
/*
	Class constructor
*/
{
	std::ostringstream cout;

	_totalAmount += initial_deposit;
	cout << time() << index() << amount() << "created;";
	flush(cout);
}

Account::~Account()
/*
	Class destructor
*/
{
	std::ostringstream cout;

	--_nbAccounts;
	cout << time() << index() << amount() << "closed;";
	flush(cout);
}

__UNUSED int
Account::getNbAccounts()
/*
	getter function for
	_nbAccounts
*/
{
	return _nbAccounts;
}

__UNUSED int
Account::getTotalAmount()
/*
	getter function for
	_totalAmount
*/
{
	return _totalAmount;
}

__UNUSED int
Account::getNbDeposits()
/*
	getter function for
	_totalNbDeposits
*/
{
	return _totalNbDeposits;
}

__UNUSED int
Account::getNbWithdrawals()
/*
	getter function for
	_totalNbWithdrawals
*/
{
	return _totalNbWithdrawals;
}

void
Account::displayAccountsInfos()
/*
	prints account information to stdout
*/
{
	std::ostringstream cout;

	cout << time() << accounts() << total() << total_deposits()
		<< total_withdrawals();
	flush(cout);
}

void
Account::makeDeposit(int _deposit)
/*
	API function - increase money in account and prints log to stdout
*/
{
	std::ostringstream cout;

	++_totalNbDeposits;
	++_nbDeposits;
	_last_deposit = _deposit;
	cout << time() << index() << p_amount();
	_amount += _deposit;
	_totalAmount += _deposit;
	cout << deposit() << amount() << nb_deposits();
	flush(cout);
}

bool
Account::makeWithdrawal(int _withdrawal)
/*
	API function - decrease money in account and prints log to stdout
*/
{
	std::ostringstream cout;

	_last_withdrawal = _withdrawal;
	cout << time() << index() << p_amount() << withdrawal();
	if (_amount < _withdrawal)
	{
		flush(cout);
		return false;
	}
	_amount -= _withdrawal;
	_totalAmount -= _withdrawal;
	++_totalNbWithdrawals;
	++_nbWithdrawals;
	cout << amount() << nb_withdrawals();
	flush(cout);
	return true;
}

__UNUSED int
Account::checkAmount() const
/*
	getter function for
	_amount
*/
{
	return _amount;
}

void
Account::displayStatus() const
/*
	prints global information to stdout
*/
{
	std::ostringstream cout;

	cout << time() << index() << amount() << deposits()
		<< withdrawals();
	flush(cout);
}

__UNUSED void
Account::_displayTimestamp()
/*
	prints global time to stdout
*/
{
	std::cout << time();
}

std::string
Account::time()
/*
	internal function - return string representation for current global time
*/
{
	return "[19920104_091532] ";
}

std::string
Account::index() const
/*
	internal function - return log quantity for _accountIndex
*/
{
	return "index:" + tlucanti::to_string(_accountIndex) + ';';
}

std::string
Account::amount() const
/*
	internal function - return log quantity for _amount
*/
{
	return "amount:" + tlucanti::to_string(_amount) + ';';
}

std::string
Account::total()
/*
	internal function - return log quantity for _totalAmount
*/
{
	return "total:" + tlucanti::to_string(_totalAmount) + ';';
}

std::string
Account::deposits() const
/*
	internal function - return log quantity for _nbDeposits
*/
{
	return "deposits:" + tlucanti::to_string(_nbDeposits) + ';';
}

std::string
Account::withdrawals() const
/*
	internal function - return log quantity for _nbWithdrawals
*/
{
	return "withdrawals:" + tlucanti::to_string(_nbWithdrawals) + ';';
}

std::string
Account::total_deposits()
/*
	internal function - return log quantity for _totalNbDeposits
*/
{
	return "deposits:" + tlucanti::to_string(_totalNbDeposits) + ';';
}

std::string
Account::total_withdrawals()
/*
	internal function - return log quantity for _totalNbWithdrawals
*/
{
	return "withdrawals:" + tlucanti::to_string(_totalNbWithdrawals) + ';';
}

std::string
Account::p_amount() const
/*
	internal function - return log quantity for _amount
*/
{
	return "p_amount:" + tlucanti::to_string(_amount) + ';';
}

std::string
Account::nb_deposits() const
/*
	internal function - return log quantity for _amount
*/
{
	return "nb_deposits:" + tlucanti::to_string(_nbDeposits) + ';';
}

std::string
Account::nb_withdrawals() const
/*
	internal function - return log quantity for _nbWithdrawals
*/
{
	return "nb_withdrawals:" + tlucanti::to_string(_nbWithdrawals) + ';';
}

std::string
Account::accounts()
/*
	internal function - return log quantity for _nbAccounts
*/
{
	return "accounts:" + tlucanti::to_string(_nbAccounts) + ';';
}

std::string
Account::deposit() const
/*
	internal function - return log quantity for _last_deposit
*/
{
	return "deposit:" + tlucanti::to_string(_last_deposit) + ';';
}

std::string
Account::withdrawal() const
/*
	internal function - return log quantity for _last_withdrawal
	if account has not enough money - withdrawal will refused
*/
{
	if (_amount < _last_withdrawal)
		return "withdrawal:refused;";
	return "withdrawal:" + tlucanti::to_string(_last_withdrawal) + ';';
}

void
Account::flush(std::ostringstream &cout)
{
	std::string outs = cout.str();
	outs[outs.size() - 1] = '\n';
	std::cout << outs;
}

#if __cplusplus <= 199711L
/*
	default constructor
*/
__UNUSED Account::Account()
	: _accountIndex(0), _amount(0), _nbDeposits(0),
	  _nbWithdrawals(0), _last_deposit(0), _last_withdrawal(0)
{}
#else
Account::Account() = default;
#endif
