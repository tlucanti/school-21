/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:07:14 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 12:51:41 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(const tlucanti::Point<tlucanti::Fixed> &a,
		 const tlucanti::Point<tlucanti::Fixed> &b,
		 const tlucanti::Point<tlucanti::Fixed> &c,
		 const tlucanti::Point<tlucanti::Fixed> &point);

#include <cstdio>

struct pair
{
	int x;
	int y;
};

float sign(const pair &pt1, const pair &pt2, const pair &pt3) {
// which side of plane cut by line (pt2, pt3) is pt1 on?
	return (pt1.x - pt3.x) * (pt2.y - pt3.y) - (pt2.x - pt3.x) * (pt1.y - pt3.y);
}

bool iswithin(const pair &pt1, const pair &pt2, const pair &pt3, const pair &point) {
/*
	Determine if point is within triangle formed by points p1, p2, p3.
	If so, the point will be on the same side of each of the half planes
		defined by vectors p1p2, p2p3, and p3p1. zval is positive if outside,
	negative if inside such a plane. All should be positive or all negative
	if point is within the triangle.
*/
	float zval1 = sign(point, pt1, pt2);
	float zval2 = sign(point, pt2, pt3);
	float zval3 = sign(point, pt3, pt1);
	bool notanyneg = zval1 >= 0 and zval2 >= 0 and zval3 >= 0;
	bool notanypos = zval1 <= 0 and zval2 <= 0 and zval3 <= 0;
	return notanyneg or notanypos;
}

#if __cplusplus > 199711L
# include <random>
# include <vector>
# include <cstdio>

#include <iostream>
int main()
{
//	{
//		tlucanti::Fixed a(0.41f);
//		tlucanti::Fixed b(3);
//		std::cout << a * b << std::endl;
//		return 0;
//	}

    std::random_device rd;
    std::mt19937 e2(rd());

    std::vector<std::pair<int, int>> borders = {
        {0, 100}, {-100, 100},
//		{0, 2047}, {-2047, 2047},
//        {-0.1, 0.1}
    };

    int all = 0;
    int ok = 0;

    for (auto b : borders)
    {
//		std::uniform_real_distribution<float> rand(b.first, b.second);
		std::uniform_int_distribution<int> rand(b.first, b.second);

        for (int i=0; i < 100000; ++i)
        {
            int x1 = rand(e2);
            int y1 = rand(e2);
            int x2 = rand(e2);
            int y2 = rand(e2);
            int x3 = rand(e2);
            int y3 = rand(e2);
            int xp = rand(e2);
            int yp = rand(e2);

            bool ans1 = iswithin({x1, y1}, {x2, y2}, {x3, y3}, {xp, yp});
            bool ans2 = bsp({x1, y1}, {x2, y2}, {x3, y3}, {xp, yp});

            ++all;
            if (ans1 == ans2)
                ++ok;
            else
            {
                printf("wrong: (%g, %g), (%g, %g), (%g, %g): (%g, %g)\n",
                    x1, y1, x2, y2, x3, y3, xp, yp);
                printf("expected %s, got %s\n", ans1 ? "true" : "false",
                    ans2 ? "true" : "false");
				bsp({x1, y1}, {x2, y2}, {x3, y3}, {xp, yp});
            }
        }
    }
	printf("%d / %d tests passed\n", ok, all);
}
 
#else

int main()
{
	srand(time(NULL));

    int all = 0;
    int ok = 0;

	for (int i=0; i < 100000; ++i)
	{
		int x1 = rand() % 100;
		int y1 = rand() % 100;
		int x2 = rand() % 100;
		int y2 = rand() % 100;
		int x3 = rand() % 100;
		int y3 = rand() % 100;
		int xp = rand() % 100;
		int yp = rand() % 100;

		const tlucanti::Point<tlucanti::Fixed> a(x1, y1);
		const tlucanti::Point<tlucanti::Fixed> b(x2, y2);
		const tlucanti::Point<tlucanti::Fixed> c(x3, y3);
		const tlucanti::Point<tlucanti::Fixed> p(xp, yp);

		const pair pa = {x1, y1};
		const pair pb = {x2, y2};
		const pair pc = {x3, y3};
		const pair pp = {xp, yp};

		bool ans1 = iswithin(pa, pb, pc, pp);
		bool ans2 = bsp(a, b, c, p);

		++all;
		if (ans1 == ans2)
			++ok;
	}
    if (all == ok)
        std::cout << "[ OK ] all tests passed\n";
    else
        std::cout << ok << " / " << all << " tests passed\n";
}

#endif
