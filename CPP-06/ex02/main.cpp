/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:46:14 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 19:07:10 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#if __cplusplus <= 199911L
typedef std::exception bad_cast;
#else
typedef std::bad_cast bad_cast;
#endif

#include "defs.h"

namespace tlucanti
{
	struct Base { virtual ~Base() __DEFAULT };
	struct A : public Base {};
	struct B : public Base {};
	struct C : public Base {};

	int random(int start, int stop)
	{
		int		ret;
		do {
			ret = rand();
		} while (ret >= RAND_MAX - RAND_MAX % (stop - start + 1));
		return ret % (stop - start + 1) + start;
	}

	Base *generate()
	{
		switch (random(1, 3))
		{
			case 1:
				std::cout << "created A ";
				return new A;
			case 2:
				std::cout << "created B ";
				return new B;
			case 3:
				std::cout << "created C ";
				return new C;
			default:
				return nullptr;
		}
	}

	void identify(Base *p)
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A ";
		else if (dynamic_cast<B *>(p))
			std::cout << "B ";
		else if (dynamic_cast<C *>(p))
			std::cout << "C ";
		else
			std::cout << "unknown";
	}

	void identify(Base &p)
	{
		try
		{
			__UNUSED A &a = dynamic_cast<A &>(p);
			std::cout << "A ";
			return ;
		} catch (bad_cast &e) {}
		try
		{
			__UNUSED B &b = dynamic_cast<B &>(p);
			std::cout << "B ";
			return ;
		} catch (bad_cast &e) {}
		try
		{
			__UNUSED C &c = dynamic_cast<C &>(p);
			std::cout << "C ";
			return ;
		} catch (bad_cast &e) {}
	}
}

int main()
{
	srand(time(nullptr));

	for (int i=0; i < 10; ++i)
	{
		tlucanti::Base *b = tlucanti::generate();
		tlucanti::identify(b);
		tlucanti::identify(*b);
		std::cout << std::endl;
		delete b;
	}
}
