/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <tlucanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:21:25 by tlucanti          #+#    #+#             */
/*   Updated: 2022/01/28 16:49:48 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

tlucanti::Span &
tlucanti::Span::operator =(const tlucanti::Span &cpy)
{
	if (this == &cpy)
		return *this;
	set = cpy.set;
	size = cpy.size;
	min = cpy.min;
	max = cpy.max;
	return *this;
}

void
tlucanti::Span::addNumber(int n)
{
	if ((int)set.size() >= size)
		throw std::length_error("set is full");
	if (set.size() == 0)
	{
		set.insert(n);
		return ;
	}
	else if (set.size() == 1)
	{
		set.insert(n);
		min = *set.begin();
		max = *(--set.end());
		return ;
	}
	if (max - min == 1)
	{
		set.insert(n);
		return ;
	}
	int left;
	int right;

	std::set<int>::iterator it = set.insert(n).first;
	if (it == set.begin())
		left = -1;
	else
	{
		left = *--it;
		++it;
		left = std::abs(left - *it);
	}

	if (it == --set.end())
		right = -1;
	else
	{
		right = *++it;
		--it;
		right = std::abs(right - *it);
	}

	if (left != -1)
	{
		if (left < std::abs(max - min))
		{
			max = *it;
			min = *--it;
		}
	}
	if (right != -1)
	{
		if (right < std::abs(max - min))
		{
			min = *it;
			max = *++it;
		}
	}
}

int
tlucanti::Span::longestSpan() const
{
	if (set.size() < 2)
		throw std::length_error("cannot create span without 2 elements");
	return *--set.end() - *set.begin();
}

int
tlucanti::Span::shortestSpan() const
{
	if (set.size() < 2)
		throw std::length_error("cannot create span without 2 elements");
	return max - min;
}
