/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:19:08 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 23:49:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Array.hpp"

int main()
{
	{
		tlucanti::Array<int> a;
		std::cout << a.size() << std::endl;
	}
	{
		tlucanti::Array<int> a(5);
		std::cout << a.size() << std::endl;
		std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] <<
			' ' << a[4] << std::endl;
	}
	{
		tlucanti::Array<int> a(1);
		std::cout << a[0] << ' ';
		a[0] = 6;
		std::cout << a[0] << std::endl;
	}
	{
		tlucanti::Array<int> a(5);
		try
		{
			std::cout << a[5];
		}
		catch (std::out_of_range &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		tlucanti::Array<int> a(1);
		a[0] = 123;
		tlucanti::Array<int> b(a);
		std::cout << a[0] << ' ' << b[0] << std::endl;
	}
	{
		tlucanti::Array<int> a(1);
		a[0] = 123;
		tlucanti::Array<int> b(1);
		b[0] = 456;
		a = b;
		std::cout << a[0] << ' ' << b[0] << std::endl;
	}
	{
		tlucanti::Array<std::string> a(5);
		std::cout << a[0] << a[1] << a[2] << a[3] << a[4] << std::endl;
		a[0] = "1";
		a[1] = "2";
		a[2] = "3";
		a[3] = "4";
		a[4] = "5";
		std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] <<
				  ' ' << a[4] << std::endl;
	}
	{
		tlucanti::Array<tlucanti::Array<int> > v(4);
		std::cout << v.size() << std::endl;
		for (int i=0; i < (int)v.size(); ++i)
			std::cout << v[i].size() << ' ';
		std::cout << std::endl;
	}
}
