/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:00:23 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:34:40 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

void	point_mul_num(t_point *p, float num)
{
	p->x *= num;
	p->y *= num;
	p->z *= num;
}

void	point_mul_point(t_point *p, t_point *to_mul)
{
	p->x *= to_mul->x;
	p->y *= to_mul->y;
	p->z *= to_mul->z;
}

void	point_plus_num(t_point *p, float to_sum)
{
	p->x += to_sum;
	p->y += to_sum;
	p->z += to_sum;
}

void	point_plus_point(t_point *p, t_point *to_sum)
{
	p->x += to_sum->x;
	p->y += to_sum->y;
	p->z += to_sum->z;
}
