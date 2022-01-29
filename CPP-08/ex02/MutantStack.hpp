/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <tlucanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:54:58 by tlucanti          #+#    #+#             */
/*   Updated: 2022/01/29 10:57:53 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "defs.h"
#include <stack>

namespace tlucanti
{
	template <typename type_T>
	class MutantStack : public std::stack<type_T> {
	public:
		typedef type_T value_type;
		typedef std::stack<value_type> stack;
		typedef typename stack::container_type::iterator iterator;
		typedef typename stack::container_type::const_iterator const_iterator;

		MutantStack() __DEFAULT

		MutantStack(const stack &cpy)
				: stack(cpy) {}

		__WUR iterator begin()
		{
			return this->c.begin();
		}

		__WUR iterator end()
		{
			return this->c.end();
		}

		__WUR const_iterator cbegin()
		{
			return this->c.cbegin();
		}

		__WUR const_iterator cend()
		{
			return this->c.cend();
		}
	};
}
