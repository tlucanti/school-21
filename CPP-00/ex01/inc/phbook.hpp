/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phbook.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:44:23 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 20:12:07 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHBOOK_HPP
# define PHBOOK_HPP

#include <iostream>
#include <iomanip>

#include "../inc/color.hpp"

namespace tlucanti
{
	class color;

	template <typename type_t>
	std::string to_string(const type_t &x)
	{
		return static_cast<std::ostringstream &>((
			std::ostringstream() << std::dec << x)).str();
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
#if __cplusplus > 199711L
	~phbook() = default;
	phbook(const phbook &) = delete;
	phbook &operator=(const phbook &) = delete;
#endif
	phbook()
		: last(0),  fullness(0)
		{}

	void
	add(std::string &fname, std::string &lname, std::string &nickname,
		unsigned long long number, std::string &secret)
	{
#if __cplusplus > 199711L
		storage[last] = std::move(contact(fname, lname, nickname, number,
			secret));
#else
		storage[last] = contact(fname, lname, nickname, number,
			secret);
#endif
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
#if __cplusplus > 199711L
			std::cout << tlucanti::color::white
				<< "index " << i << " information:" << tlucanti::color::reset << std::endl;
#else
			std::cout << tlucanti::color::white
				<< "index " << i << " information:" << tlucanti::color::reset << std::endl;
#endif
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
#if __cplusplus > 199711L
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
#else
		contact()
		{}
		contact(std::string &_fname, std::string &_lname,
			std::string &_nickname, unsigned long long _number,
			std::string &_secret)
				: fname(_fname), lname(_lname),
			nickname(_nickname), number(_number),
			secret(_secret)
			{}

		contact &operator =(contact _mv)
		{
			fname = _mv.fname;
			lname = _mv.lname;
			nickname = _mv.nickname;
			number = _mv.number;
			secret = _mv.secret;
			return (*this);
		}
#endif


		std::string str(long idx) const
		{
			std::string ss = "";
			ss += "│" + truncate(idx) + "│"  + truncate(fname) + "│"
				+ truncate(lname) + "│" + truncate(nickname) + "│";
			return (ss);
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
#if __cplusplus > 199711L
		unsigned long long number = 0;
#else
		unsigned long long number;
#endif
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
