/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:58:03 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/17 18:09:14 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

t_point	point_stack(float x, float y, float z)
{
	t_point		new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	return (new_point);
}

t_point	point_copy_stack(t_point *to_cpy)
{
	t_point		new_point;

	new_point.x = to_cpy->x;
	new_point.y = to_cpy->y;
	new_point.z = to_cpy->z;
	return (new_point);
}

t_point	point_plus_stack(t_point *p1, t_point *p2)
{
	t_point		new_point;

	new_point.x = p1->x + p2->x;
	new_point.y = p1->y + p2->y;
	new_point.z = p1->z + p2->z;
	return (new_point);
}

t_point	point_minus_stack(t_point *p1, t_point *p2)
{
	t_point		new_point;

	new_point.x = p1->x - p2->x;
	new_point.y = p1->y - p2->y;
	new_point.z = p1->z - p2->z;
	return (new_point);
}

t_point	point_cross_stack(t_point *p1, t_point *p2)
{
	t_point		new_point;

	new_point.x = det2(p1->y, p1->z, p2->y, p2->z);
	new_point.y = -(det2(p1->x, p1->z, p2->x, p2->z));
	new_point.z = det2(p1->x, p1->y, p2->x, p2->y);
	return (new_point);
}
