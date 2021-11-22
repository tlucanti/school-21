// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <functional>
#if __cplusplus <= 199711L
# include <algorithm>
#endif
#include "Account.hpp"

int		main() {
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
#if __cplusplus <= 199711L
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();
#else
	auto				acc_begin	= accounts.begin();
	auto				acc_end		= accounts.end();
#endif
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
#if __cplusplus <= 199711L
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();
#else
	auto				dep_begin	= deposits.begin();
	auto				dep_end		= deposits.end();
#endif
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
#if __cplusplus <= 199711L
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();
#else
	auto				wit_begin	= withdrawals.begin();
	auto				wit_end		= withdrawals.end();
#endif
	Account::displayAccountsInfos();
#if __cplusplus <= 199711L
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
#else
	std::for_each( acc_begin, acc_end, std::mem_fn( &Account::displayStatus ) );
#endif
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
#if __cplusplus <= 199711L
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
#else
	std::for_each( acc_begin, acc_end, std::mem_fn( &Account::displayStatus ) );
#endif
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
#if __cplusplus <= 199711L
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
#else
	std::for_each( acc_begin, acc_end, std::mem_fn( &Account::displayStatus ) );
#endif
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
