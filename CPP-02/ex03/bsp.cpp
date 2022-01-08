/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:17:13 by kostya            #+#    #+#             */
/*   Updated: 2022/01/08 19:11:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(const  tlucanti::Point<tlucanti::Fixed> &a,
		 const  tlucanti::Point<tlucanti::Fixed> &b,
		 const  tlucanti::Point<tlucanti::Fixed> &c,
		 const  tlucanti::Point<tlucanti::Fixed> &point)
{
	tlucanti::Fixed FIX_EPS(0.01f);

	tlucanti::Fixed s1 = tlucanti::Point<tlucanti::Fixed>::cross_product(b, point, a);
	tlucanti::Fixed s2 = tlucanti::Point<tlucanti::Fixed>::cross_product(c, point, b);
	tlucanti::Fixed s3 = tlucanti::Point<tlucanti::Fixed>::cross_product(a, point, c);

	return (a - point).sq_length().abs() <= FIX_EPS ||
		(b - point).sq_length().abs() <= FIX_EPS ||
		(c - point).sq_length().abs() <= FIX_EPS ||
		(s1 <= FIX_EPS and s2 <= FIX_EPS and s3 <= FIX_EPS) ||
		(s1 >= -FIX_EPS and s2 >= -FIX_EPS and s3 >= -FIX_EPS);
}
