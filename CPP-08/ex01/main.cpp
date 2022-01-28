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

int _rand_start;
int _rand_stop;

void rand_init(int start, int stop)
{
	_rand_start = start;
	_rand_stop = stop;
	srand(time(nullptr));
}

int randint()
{
	int start = _rand_start;
	int stop = _rand_stop;

	int		ret;
	do {
		ret = rand();
	} while (ret >= RAND_MAX - RAND_MAX % (stop - start + 1));
	return ret % (stop - start + 1) + start;
}
#else

std::uniform_int_distribution<std::mt19937::result_type> *_dist;
std::mt19937 *_rng;
void rand_init(int start, int stop)
{
	std::random_device dev;
    std::mt19937 rng(dev());
	_rng = &rng;
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, stop);
	_dist = &dist;
}

int randint()
{
	return *_dist(*_rng);
}

#endif

int main()
{
	{
		tlucanti::Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		rand_init(1, 10);
		tlucanti::Span sp(100);
		for (int i=0; i < 100; ++i)
		{
			sp.addNumber(randint());
			if (i >= 2)
				std::cout << sp.longestSpan() << ' ' << sp.shortestSpan() << std::endl;
		}
	}
}