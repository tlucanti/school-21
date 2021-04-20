/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:44:28 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/18 12:32:25 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

float	dot(t_point *a, t_point *b)
{
	return ((a)->x * (b)->x + (a)->y * (b)->y + (a)->z * (b)->z);
}

float	det2(float a1, float a2, float b1, float b2)
{
	return (a1 * b2 - a2 * b1);
}

t_point	*normalize(t_point *n)
{
	point_mul_num(n, 1.f / sqrtf(dot(n, n)));
	return (n);
}

t_point	*normalize_fast(t_point *n)
{
	normalize(n);
	return (n);
}
