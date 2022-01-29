/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <tlucanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:49:48 by tlucanti          #+#    #+#             */
/*   Updated: 2022/01/28 16:56:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>

#include "defs.h"

namespace tlucanti
{
    class Span
    {
	public:
        Span(int n)
			: size(n) {}
		Span(const Span &cpy)
			: set(cpy.set), size(cpy.size), min(cpy.min), max(cpy.max) {}
		~Span() __DEFAULT
		Span &operator =(const Span &cpy);
		__WUR int shortestSpan() const;
		__WUR int longestSpan() const;
		void addNumber(int n);

		template<typename InputIterator>
		void addNumber(InputIterator start, InputIterator stop)
		{
			for (; start != stop; ++start)
				addNumber(*start);
		}

	private:
		Span() __DEFAULT;
		std::set<int> set;
		int size;
		int min;
		int max;
	};
}
