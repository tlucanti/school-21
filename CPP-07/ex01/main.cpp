/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:10:51 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 20:22:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

template <typename type_T>
type_T pr(const type_T &v)
{
	std::cout << v << " ";
	return v;
}

template <typename type_T>
type_T inc(type_T c)
{
	++c;
	std::cout << c << " ";
	return c;
}

int main()
{
	{
		int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
		tlucanti::iter(a, 10u, pr<int>);
		std::cout << std::endl;
		tlucanti::iter(a, 10L, pr<long>);
		std::cout << std::endl;
		tlucanti::iter(a, 10ul, pr<float>);
		std::cout << std::endl;
		tlucanti::iter(a, 10, inc<unsigned long long>);
		std::cout << std::endl;
	}
	{
		char hello[] = "Hello, world!";
		tlucanti::iter(hello, sizeof(hello), pr<char>);
		std::cout << std::endl;
		tlucanti::iter(hello, 13, inc<char>);
		std::cout << std::endl;
	}
	{
		std::string str = "string_lol";
		tlucanti::iter(const_cast<char *>(str.c_str()), str.size(), pr<char>);
		std::cout << std::endl;
		tlucanti::iter(const_cast<char *>(str.c_str()), 10, inc<int>);
		std::cout << std::endl;
	}
}
