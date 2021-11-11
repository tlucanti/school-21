/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phbook.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:44:23 by kostya            #+#    #+#             */
/*   Updated: 2021/11/09 15:49:00 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHBOOK_HPP
# define PHBOOK_HPP

#include <iostream>
#include <iomanip>
#include "color.hpp"

namespace tlucanti
{

std::string to_string(const std::string &str)
{
	return str;
}

template <typename type_t>
std::string to_string(type_t &val)
{
	return std::to_string(val);
}

template<std::size_t _Nm>
class phbook
/**
 *  @brief  Extended manipulator for inserting money.
 *  @param  __mon  Either long double or a specialization of @c basic_string.
 *  @param  __intl A bool indicating whether international format
 *                 is to be used.
 *
 *  Sent to a stream object, this manipulator inserts @a __mon.
*/
{
public:
	~phbook() = default;
	phbook(const phbook &) = delete;
	phbook &operator=(const phbook &) = delete;

	phbook()
		: last(0),  fullness(0)
		{}

	void
	add(std::string &fname, std::string &lname, std::string &nickname,
		unsigned long long number, std::string &secret)
	{
		std::cout << "adding " << last << "\n";
		storage[last] = std::move(contact(fname, lname, nickname, number,
			secret));
		last = (last + 1) % _Nm;
		fullness = std::min((std::size_t)fullness + 1, _Nm);
	}

	int
	search(long i) const
	{
		std::cout << "╭──────────┬──────────┬──────────┬──────────╮\n";
		std::cout << "│   index  │first name│last  name│ nickname │\n";
		std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
		for (long j=0; j < fullness; ++j)
			std::cout << storage[(fullness + last - j - 1) % fullness].str(j + 1)
				<< std::endl;
		std::cout << "╰──────────┴──────────┴──────────┴──────────╯\n";
		if (i != -1 and (i < 1 or i > fullness))
			return 1;
		if (i != -1)
		{
			std::cout << tlucanti::color::white
				<< "index " << i << " information:"_reset << std::endl;
			long _idx = (fullness + last - i) % fullness;
			std::cout << "  first name: " << storage[_idx].fname << std::endl;
			std::cout << "  last name : " << storage[_idx].lname << std::endl;
			std::cout << "  nickname  : " << storage[_idx].nickname << std::endl;
			std::cout << "  phone num : " << storage[_idx].number << std::endl;
		}
		return 0;
	}

	class contact
	{
	public:
		contact() = default;
		~contact() = default;
		contact(const contact &) = delete;
		contact &operator =(contact &_mv) = delete;

		contact(std::string &_fname, std::string &_lname,
			std::string &_nickname, unsigned long long _number,
			std::string &_secret)
				: fname(std::move(_fname)), lname(std::move(_lname)),
			nickname(std::move(_nickname)), number(_number),
			secret(std::move(_secret))
			{}

		contact &operator =(contact &&_mv) noexcept
		{
			fname = std::move(_mv.fname);
			lname = std::move(_mv.lname);
			nickname = std::move(_mv.nickname);
			number = _mv.number;
			secret = std::move(_mv.secret);
			return (*this);
		}

		std::string str(long idx) const
		{
			std::stringstream ss("", std::ios_base::app | std::ios_base::out);

			ss << "│" << truncate(idx) << "│"  << truncate(fname) << "│"
				<< truncate(lname) << "│" << truncate(nickname) << "│";
			return (ss.str());
		}

		template <typename type_t>
		static std::string truncate(const type_t &v, long w=10)
		{
			std::string out = tlucanti::to_string(v) + std::string(w, ' ');
			out = out.substr(0, w);
			if (out[w - 1] != ' ')
				out[w - 1] = '.';
			return (out);
		}

		std::string fname;
		std::string lname;
		std::string nickname;
		unsigned long long number = 0;
	private:
		std::string secret;
	};

private:
	long last;
	long fullness;

	phbook::contact storage[_Nm];
};

} // namespace::tlucanti


#endif // PHBOOK_HPP
