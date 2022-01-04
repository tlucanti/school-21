// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#ifndef __ACCOUNT_H__
# define __ACCOUNT_H__
# if __cplusplus <= 199711L
#  define __UNUSED __attribute__((unused))
#  define __DECLARE
#  define __WUR __attribute__((warn_unused_result))
# else
#  define __UNUSED [[maybe_unused]]
#  define __DECLARE {}
#  define __WUR [[nodiscard]]
# endif

# include <iostream>
# include <string>
# include <sstream>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	__UNUSED static	int		getNbAccounts();
	__UNUSED static	int		getTotalAmount();
	__UNUSED static	int		getNbDeposits();
	__UNUSED static	int		getNbWithdrawals();
	__UNUSED static	void	displayAccountsInfos();

	explicit Account(int initial_deposit);
	~Account();

	void	makeDeposit(int deposit);
	bool	makeWithdrawal(int withdrawal);
	__UNUSED __WUR int		checkAmount() const;
	void	displayStatus() const;


private:

	static	int	_nbAccounts;
	static	int	_totalAmount;
	static	int	_totalNbDeposits;
	static	int	_totalNbWithdrawals;

	__UNUSED static void	_displayTimestamp();

	int				_accountIndex __DECLARE;
	int				_amount __DECLARE;
	int				_nbDeposits __DECLARE;
	int				_nbWithdrawals __DECLARE;

	__WUR			std::string	index() const;
	__WUR			std::string	amount() const;
	__WUR			std::string	deposits() const;
	__WUR			std::string	withdrawals() const;
	__WUR			std::string	p_amount() const;
	__WUR			std::string	nb_deposits() const;
	__WUR 			std::string	nb_withdrawals() const;
	__WUR			std::string	deposit() const;
	__WUR			std::string	withdrawal() const;
	__WUR static	std::string	time();
	__WUR static	std::string	total();
	__WUR static	std::string	total_deposits();
	__WUR static	std::string	total_withdrawals();
	__WUR static	std::string	accounts();

	static void flush(std::ostringstream &cout);

	int	_last_deposit __DECLARE;
	int	_last_withdrawal __DECLARE;

	Account();
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
