/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:07:28 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 19:57:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace tlucanti
{
	template <typename Point_T>
	class Point
	{
	public:
		Point() {}
		~Point() {}
		Point(const Point<Point_T> &cpy)
			: x(cpy.x), y(cpy.y) {}
		Point(const float _x, const float _y)
			: x(_x), y(_y) {}
		Point(const int _x, const int _y)
			: x((float)_x), y((float)_y) {}
		Point(const Point_T &_x, const Point_T &_y)
			: x(_x), y(_y) {}

		Point<Point_T> operator =(const Point<Point_T> &cpy)
		{
			return Point(cpy);
		}

		Point<Point_T> operator -(const Point<Point_T> &other) const
		{
			return Point(x - other.x, y - other.y);
		}

		Point_T operator *(const Point<Point_T> &other) const
		{
			return x * other.y - y * other.x;
		}

		static Point_T cross_product(const Point<Point_T> &start,
			const Point<Point_T> &a, const Point<Point_T> &b)
		{
			return (a - start) * (b - start);
		}

		Point_T sq_length() const
		{
			return x * x + y * y;
		}

	private:
		const Point_T x;
		const Point_T y;
	};
}

