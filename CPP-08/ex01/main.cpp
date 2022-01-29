/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <tlucanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:21:25 by tlucanti          #+#    #+#             */
/*   Updated: 2022/01/28 22:02:21 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <vector>
#include <iostream>

#if __cpluplus <= 199711L

# include <ctime>
# include <cstdlib>

typedef std::pair<int, int> rand_dev;

__WUR
rand_dev rand_init(int start, int stop)
{
	srand(time(nullptr));
	return rand_dev(start, stop);
}

int randint(rand_dev &dev)
{
	int start = dev.first;
	int stop = dev.second;

	int		ret;
	do {
		ret = rand();
	} while (ret >= RAND_MAX - RAND_MAX % (stop - start + 1));
	return ret % (stop - start + 1) + start;
}
#else

# include <random>

typedef std::mt19937 dev_type;
typedef std::uniform_int_distribution<dev_type::result_type> dist_type;
typedef std::pair<dev_type, dist_type> rand_dev;

__WUR
rand_dev rand_init(int start, int stop)
{
	std::random_device dev;
	dev_type rng(dev());
	dist_type dist(start, stop);
	return rand_dev(dev, dist);
}

int randint(rand_dev &dev)
{
	return (int)dev.second(dev.first);
}

#endif

int main()
{
	{
		std::cout << "test 1\n";
		tlucanti::Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(17);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(9);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(11);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "test 2\n";
		tlucanti::Span sp(5);
		sp.addNumber(2);
		sp.addNumber(8);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(5);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(0);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
		sp.addNumber(6);
		std::cout << "  " << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "test 3\n";
		rand_dev rng = rand_init(1, 10);
		tlucanti::Span sp(10);
		for (int i=0; i < 20; ++i)
		{
			sp.addNumber(randint(rng));
			if (i >= 2)
				std::cout << "  " << sp.longestSpan() << ' ' << sp.shortestSpan() << std::endl;
		}
	}
	{
		std::cout << "test4 \n";
		tlucanti::Span sp(1);
		sp.addNumber(1);
		try {
			__UNUSED int _;
			_ = sp.shortestSpan();
		} catch (std::length_error &exc) {
			std::cout << exc.what() << std::endl;
		} try {
			__UNUSED int _;
			_ = sp.longestSpan();
		} catch (std::length_error &exc) {
			std::cout << exc.what() << std::endl;
		} try {
			sp.addNumber(123);
		} catch (std::length_error &exc) {
			std::cout << exc.what() << std::endl;
		}
	}
	{
		std::cout << "test 5\n";
		rand_dev rng = rand_init(-100000, 100000);
		tlucanti::Span sp(100000);
		for (int i=0; i < 100000; ++i)
		{
			sp.addNumber(randint(rng));
		}
	}
	{
		std::cout << "test 6\n";
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		tlucanti::Span sp(3);
		sp.addNumber(v.begin(), v.end());
		std::cout << sp.shortestSpan() << ' ' << sp.longestSpan() << std::endl;
	}
}