/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:38:37 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 19:55:16 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

#define _swap(a, b) \
do { \
	std::cout << (a) << " " << (b) << std::endl; \
	tlucanti::swap(a, b); \
	std::cout << (a) << " " << (b) << std::endl; \
} while (false)

#define test(a, b) \
do { \
	std::cout << "min " << tlucanti::min(a, b) << std::endl; \
	std::cout << "max " << tlucanti::max(a, b) << std::endl; \
} while (false)

int main()
{
	std::cout << "-----------\n";
	std::cout << "swap test\n";
	{
		int a = 1;
		int b = 2;
		std::cout << "int\n";
		_swap(a, b);
	}
	{
		const char *a = "Hello";
		const char *b = "world!";
		std::cout << "char\n";
		_swap(a, b);
	}
	{
		std::string a = "aaaaaa";
		std::string b = "bbb";
		std::cout << "string\n";
		_swap(a, b);
	}
	std::cout << "-----------\n";
	std::cout << "min/max test\n";
	{
		int a = 1;
		int b = 2;
		std::cout << "int\n";
		test(a, b);
	}
	{
		std::string a = "aa";
		std::string b = "bb";
		std::cout << "string\n";
		test(a, b);
	}
}
