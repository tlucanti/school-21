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

template <typename type_T>
type_T generate(int i)
{
	type_T a;
	for (int j=0; j < i; ++j)
		a.emplace_back(j);
	return a;
}

int main()
{
	{
		typedef	std::vector<int>	T;
		T a = generate<T>(4);
		std::cout << *tlucanti::easyfind(a, 3) << std::endl;
	}
	{

	}
}
