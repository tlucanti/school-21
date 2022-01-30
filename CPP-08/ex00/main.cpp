/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:05:55 by kostya            #+#    #+#             */
/*   Updated: 2022/01/23 00:12:23 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iomanip>

template <typename type_T>
type_T generate(int i)
{
	type_T a;
	for (int j=0; j < i; ++j)
		a.push_back(j);
	return a;
}

template <typename type_T>
type_T insert(int i)
{
	type_T a;
	for (int j=0; j < i; ++j)
		a.insert(j);
	return a;
}

int main()
{
	typedef	std::vector<int>	V;
	typedef std::set<int> S;
	typedef std::set<int> M;
	{
		V a = generate<V>(4);
		std::cout << *tlucanti::easyfind(a, 3) << std::endl;
	}
	{
		V a = generate<V>(3);
		V::const_iterator it = tlucanti::easyfind(a, -1);
		std::cout << std::boolalpha << (it == a.cend()) << std::endl;
	}

	{
		S a = insert<S>(4);
		std::cout << *tlucanti::easyfind(a, 3) << std::endl;
	}
	{
		S a = insert<S>(3);
		S::const_iterator it = tlucanti::easyfind(a, -1);
		std::cout << std::boolalpha << (it == a.cend()) << std::endl;
	}

	{
		M a = insert<M>(4);
		std::cout << *tlucanti::easyfind(a, 3) << std::endl;
	}
	{
		M a = insert<M>(3);
		M::const_iterator it = tlucanti::easyfind(a, -1);
		std::cout << std::boolalpha << (it == a.cend()) << std::endl;
	}
}
