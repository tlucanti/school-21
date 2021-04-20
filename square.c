/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:19 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:20 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	square(t_square_input *inp, t_square **dest)
{
	t_square	*new_square;

	*dest = NULL;
	new_square = (t_square *)malloc(sizeof(t_square));
	if (!new_square)
		return (ft_free(inp->center) + ft_free(inp->normal) + 1);
	*dest = new_square;
	new_square->center = inp->center;
	new_square->normal = inp->normal;
	new_square->color = inp->col;
	new_square->specular = inp->specular;
	new_square->reflective = inp->reflective;
	new_square->d = inp->d / 2;
	new_square->v1 = point(inp->normal->y, -inp->normal->x, 0);
	new_square->v2 = point_cross(inp->normal, new_square->v1);
	if (!new_square->v1 || !new_square->v2)
		return (1);
	normalize(new_square->normal);
	normalize(new_square->v2);
	normalize(new_square->v1);
	return (0);
}

int	square_4p(t_triangle_input *inp, t_square **dest)
{
	t_square	*new_square;

	*dest = NULL;
	new_square = (t_square *)malloc(sizeof(t_square));
	if (!new_square)
		return (ft_free(inp->x) + ft_free(inp->y) + ft_free(inp->z) + 1);
	*dest = new_square;
	new_square->v1 = point_minus(inp->y, inp->x);
	new_square->v2 = point_minus(inp->z, inp->x);
	new_square->center = point_plus(inp->y, inp->z);
	if (!new_square->v1 || !new_square->v2 || !new_square->center)
		return (1);
	new_square->normal = point_cross(new_square->v1, new_square->v2);
	if (!new_square->normal)
		return (1);
	point_mul_num(new_square->center, 0.5f);
	new_square->d = sqrtf(dot(new_square->v1, new_square->v2));
	new_square->color = inp->col;
	new_square->specular = inp->specular;
	new_square->reflective = inp->reflective;
	normalize(new_square->normal);
	return (0);
}

float	intersect_square(t_point *o, t_point *d, t_square *square)
{
	float		dt_t1_t2_t[4];
	t_point		co;
	t_point		p;
	t_point		cp;

	dt_t1_t2_t[0] = dot(d, square->normal);
	if (dt_t1_t2_t[0] == 0)
		return (INF);
	co = point_minus_stack(square->center, o);
	dt_t1_t2_t[3] = dot(&co, square->normal) / dt_t1_t2_t[0];
	if (dt_t1_t2_t[3] < 0)
		return (INF);
	p = point_stack(o->x + d->x * dt_t1_t2_t[3], o->y + d->y * dt_t1_t2_t[3],
			o->z + d->z * dt_t1_t2_t[3]);
	cp = point_minus_stack(&p, square->center);
	dt_t1_t2_t[1] = dot(&cp, square->v1);
	dt_t1_t2_t[2] = dot(&cp, square->v2);
	dt_t1_t2_t[1] = fabsf(dt_t1_t2_t[1]);
	dt_t1_t2_t[2] = fabsf(dt_t1_t2_t[2]);
	if (dt_t1_t2_t[1] > square->d || dt_t1_t2_t[2] > square->d)
		return (INF);
	return (dt_t1_t2_t[3]);
}

float	closest_intersection_square(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	float		inter;
	int			i;

	i = 0;
	while (i < g_scene->squares_num)
	{
		inter = intersect_square(o, d, g_scene->squares[i]);
		if (inter >= t->t_min && inter <= t->t_max && inter < closest_object->t)
		{
			closest_object->t = inter;
			closest_object->id = 3;
			closest_object->obj = g_scene->squares[i];
		}
		i++;
	}
	return (closest_object->t);
}
