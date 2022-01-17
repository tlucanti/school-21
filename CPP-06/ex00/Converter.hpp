/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:42:09 by kostya            #+#    #+#             */
/*   Updated: 2022/01/18 01:04:01 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <limits>

#include "defs.h"

namespace tlucanti
{
	class Converter
	{
	public:
		explicit Converter(const char *str);

		__EXPLICIT_OPERATOR operator char() const;
		__EXPLICIT_OPERATOR operator int() const;
		__EXPLICIT_OPERATOR operator float() const;
		__EXPLICIT_OPERATOR operator double() const;

		struct ConvertationError : public std::logic_error
		{
			explicit ConvertationError(const char *what)
				: std::logic_error	(what) {}
		};

	private:
		std::string str;

		template <typename type_T>
		__WUR char _char_ss_check() const
		{
			std::stringstream ss(str);
			type_T t;

			ss >> t;
			bool ok = not ss.fail();
			char c;
			ss >> c;
			bool eof = ss.fail();
			if (ok and eof)
			{
				if (t > static_cast<type_T>(127))
					throw ConvertationError("overflow");
				if (t < static_cast<type_T>(-128))
					throw ConvertationError("underflow");
				if (std::isprint((char)t))
					return (char)t;
				throw ConvertationError("Non displayable");
			}
			throw std::invalid_argument("");
		}

		template <typename type_T>
		__WUR int _int_ss_check() const
		{
			std::stringstream ss(str);
			type_T t = 0;

			ss >> t;
			if (ss.fail() and t == std::numeric_limits<type_T>::max())
				throw ConvertationError("overflow");
			if (ss.fail() and t == std::numeric_limits<type_T>::min())
				throw ConvertationError("underflow");
			if (static_cast<type_T>(t) >
					static_cast<type_T>(std::numeric_limits<int>::max()) or
				(t > 0 and static_cast<int>(t) < 0))
				throw ConvertationError("overflow");
			if (static_cast<type_T>(t) <
					static_cast<type_T>(std::numeric_limits<int>::min()) or
				(t < 0 and static_cast<int>(t) > 0))
				throw ConvertationError("underflow");
			if (not ss.fail() and ss.eof())
				return (int)t;
			throw std::invalid_argument("");
		}

		template <typename type_T>
		type_T _float_ss_check() const
		{
			type_T f = _float_special_check<type_T>();
			if (f != 0)
				return f;

			std::stringstream ss(str);
			ss >> f;
			if (not ss.fail() and ss.eof())
				return f;
			throw ConvertationError("impossible");
		}

		template <typename type_T>
		type_T _float_special_check() const
		{
			if (str == "inf" or str == "inff")
				return std::numeric_limits<type_T>::infinity();
			if (str == "-inf" or str == "-inff")
				return -std::numeric_limits<type_T>::infinity();
			if (str == "nan" or str == "nanf")
				return std::numeric_limits<type_T>::quiet_NaN();
			if (str == "-nan" or str == "-nanf")
				return -std::numeric_limits<type_T>::quiet_NaN();
			return 0;
		}

		template <typename iter_T>
		iter_T find_if_not(iter_T start, iter_T end, int (*func)(int))
		{
			while (start != end && func(*start))
				++start;
			return start;
		}

		template<typename iter_T>
		iter_T prev(iter_T iter)
		{
			return --iter;
		}
	};
}
