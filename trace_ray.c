/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:26 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:26 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

unsigned int	trace_ray(t_point *o, t_point *d, t_pair *t,
	int recursion_depth)
{
	t_object		closest_object;
	t_point			p;
	t_point			minus_d;
	t_pair			t_req;
	unsigned int	reflected_color;

	object_switcher_0(o, d, t, &closest_object);
	if (closest_object.t == INF)
		return (BACKGROUND_COLOR);
	p = point_stack(o->x + d->x * closest_object.t, o->y + d->y * closest_object
			.t, o->z + d->z * closest_object.t);
	minus_d = point_stack(-d->x, -d->y, -d->z);
	object_switcher_1(&p, &closest_object, &minus_d);
	if (recursion_depth > RECURSION_DEPTH || closest_object.reflective <= 0)
		return (closest_object.local_color);
	reflect_ray(&minus_d, &closest_object.normal);
	t_req.t_min = EPS;
	t_req.t_max = INF;
	reflected_color = trace_ray(&p, &minus_d, &t_req, recursion_depth + 1);
	return (color_sum(color_mul(closest_object.local_color, 1 - closest_object
				.reflective), color_mul(reflected_color, closest_object
				.reflective)));
}

void	object_switcher_0(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	closest_object->t = INF;
	if (g_scene->spheres_num != 0)
		closest_intersection_sphere(o, d, t, closest_object);
	if (g_scene->planes_num != 0)
		closest_intersection_plane(o, d, t, closest_object);
	if (g_scene->triangles_num != 0)
		closest_intersection_triangle(o, d, t, closest_object);
	if (g_scene->squares_num != 0)
		closest_intersection_square(o, d, t, closest_object);
	if (g_scene->cylinders_num != 0)
		closest_intersection_cylinder(o, d, t, closest_object);
	if (g_scene->circles_num != 0)
		closest_intersection_circle(o, d, t, closest_object);
}

void	object_switcher_1(t_point *p, t_object *closest_object,
	t_point *minus_d)
{
	if (closest_object->id == 0)
	{
		closest_object->normal = point_minus_stack(p, ((t_sphere *)
					closest_object->obj)->center);
		normalize_fast(&closest_object->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_sphere *)closest_object->obj)->specular);
		closest_object->local_color = color_mul_rgb(((t_sphere *)closest_object
					->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_sphere *)closest_object->obj)
			->reflective;
	}
	else if (closest_object->id == 1)
	{
		closest_object->normal = point_copy_stack(((t_plane *)closest_object
					->obj)->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_plane *)closest_object->obj)->specular);
		closest_object->local_color = color_mul_rgb(((t_plane *)closest_object
					->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_plane *)closest_object->obj)
			->reflective;
	}
	else
		object_switcher_2(p, closest_object, minus_d);
}

void	object_switcher_2(t_point *p, t_object *closest_object,
	t_point *minus_d)
{
	if (closest_object->id == 2)
	{
		closest_object->normal = point_copy_stack(((t_triangle *)closest_object
					->obj)->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_triangle *)closest_object->obj)
				->specular);
		closest_object->local_color = color_mul_rgb(((t_triangle *)
					closest_object->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_triangle *)closest_object->obj)
			->reflective;
	}
	else if (closest_object->id == 3)
	{
		closest_object->normal = point_copy_stack(((t_square *)closest_object
					->obj)->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_square *)closest_object->obj)->specular);
		closest_object->local_color = color_mul_rgb(((t_square *)closest_object
					->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_square *)closest_object->obj)
			->reflective;
	}
	else
		object_switcher_3(p, closest_object, minus_d);
}

void	object_switcher_3(t_point *p, t_object *closest_object,
	t_point *minus_d)
{
	if (closest_object->id == 4)
	{
		closest_object->normal = point_minus_stack(p, &closest_object->normal);
		normalize_fast(&closest_object->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_cylinder *)closest_object->obj)
				->specular);
		closest_object->local_color = color_mul_rgb(((t_cylinder *)
					closest_object->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_cylinder *)closest_object->obj)
			->reflective;
	}
	else
	{
		closest_object->normal = point_copy_stack(((t_circle *)closest_object
					->obj)->normal);
		closest_object->alpha_rgb = compute_lightning(p, &closest_object
				->normal, minus_d, ((t_circle *)closest_object->obj)->specular);
		closest_object->local_color = color_mul_rgb(((t_circle *)closest_object
					->obj)->color, &closest_object->alpha_rgb);
		closest_object->reflective = ((t_circle *)closest_object->obj)
			->reflective;
	}
}
