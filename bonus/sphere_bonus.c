/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:11:48 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/14 20:11:48 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	sphere(t_sphere_input *inp, t_sphere **dest)
{
	t_sphere	*new_sphere;

	*dest = NULL;
	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
		return (ft_free(inp->center) + 1);
	new_sphere->center = inp->center;
	new_sphere->color = inp->col;
	new_sphere->specular = inp->specular;
	new_sphere->reflective = inp->reflective;
	new_sphere->radius_sq = inp->radius * inp->radius;
	*dest = new_sphere;
	return (0);
}

float	intersect_sphere(t_point *o, t_point *d, t_sphere *sphere, t_pair arg)
{
	t_point		oc;
	float		coefs[3];
	float		discr;
	float		t;

	oc = point_minus_stack(o, sphere->center);
	coefs[0] = 2.f * arg.t_max;
	coefs[1] = dot(&oc, d) * -2.f;
	coefs[2] = dot(&oc, &oc) - sphere->radius_sq;
	discr = coefs[1] * coefs[1] - 2.f * coefs[0] * coefs[2];
	if (discr < 0)
		return (INF);
	discr = sqrtf(discr);
	if (coefs[1] > 0 && discr < coefs[1])
	{
		t = (coefs[1] - discr) / coefs[0];
		if (t > arg.t_min)
			return (t);
	}
	return ((coefs[1] + discr) / coefs[0]);
}

float	closest_intersection_sphere(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	float		inter;
	t_pair		arg;
	int			i;

	arg.t_min = t->t_min;
	arg.t_max = dot(d, d);
	i = 0;
	while (i < g_scene->spheres_num)
	{
		inter = intersect_sphere(o, d, g_scene->spheres[i], arg);
		if (inter >= t->t_min && inter <= t->t_max && inter < closest_object->t)
		{
			closest_object->t = inter;
			closest_object->id = 0;
			closest_object->obj = g_scene->spheres[i];
		}
		i++;
	}
	return (closest_object->t);
}
