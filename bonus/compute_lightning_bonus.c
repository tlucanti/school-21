/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:33:25 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:25 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

t_color	compute_lightning(t_point *p, t_point *n, t_point *v, int s)
{
	t_color		intensity_rgb;
	t_point		l;
	float		arg[2];
	int			i;

	intensity_rgb = (t_color){0, 0, 0};
	i = -1;
	while (++i < g_scene->lights_num)
	{
		if (g_scene->lights[i]->type == 'a' && color_plmul_color(&intensity_rgb,
				g_scene->lights[i]->color, 1.f))
			continue ;
		*arg = color_switcher(i, p, &l);
		if (dot(&l, n) * dot(v, n) < 0 || shadow_switcher_1(p, &l, *arg) != INF)
			continue ;
		color_plmul_color(&intensity_rgb, g_scene->lights[i]->color,
			fabsf(dot(n, normalize_fast(&l))));
		if (s <= 0)
			continue ;
		arg[1] = dot(reflect_ray(&l, n), normalize_fast(v));
		if (arg[1] > 0)
			color_plmul_color(&intensity_rgb, g_scene->lights[i]->color,
				powf(arg[1], (float)s));
	}
	return (*normalize_colors(&intensity_rgb));
}

float	shadow_switcher_1(t_point *p, t_point *l, float t_max)
{
	t_pair		t_min_max;
	t_object	closest_object;
	float		t;

	t = INF;
	t_min_max.t_min = EPS;
	t_min_max.t_max = t_max;
	closest_object.t = INF;
	if (g_scene->spheres_num != 0)
		t = closest_intersection_sphere(p, l, &t_min_max, &closest_object);
	if (t != INF)
		return (0);
	if (g_scene->planes_num != 0)
		t = closest_intersection_plane(p, l, &t_min_max, &closest_object);
	if (t != INF)
		return (0);
	if (g_scene->triangles_num != 0)
		t = closest_intersection_triangle(p, l, &t_min_max, &closest_object);
	if (t != INF)
		return (0);
	if (g_scene->squares_num != 0)
		t =closest_intersection_square(p, l, &t_min_max, &closest_object);
	if (t != INF)
		return (0);
	return (shadow_switcher_2(p, l, &closest_object, t_max));
}

float	shadow_switcher_2(t_point *p, t_point *l, t_object *closest_object,
	float t_max)
{
	t_pair	t_min_max;
	float	t;

	t = INF;
	t_min_max.t_min = EPS;
	t_min_max.t_max = t_max;
	closest_object->t = INF;
	if (g_scene->cylinders_num != 0)
		t = closest_intersection_cylinder(p, l, &t_min_max, closest_object);
	if (t != INF)
		return (0);
	if (g_scene->circles_num != 0)
		t = closest_intersection_circle(p, l, &t_min_max, closest_object);
	if (t != INF)
		return (0);
	return (INF);
}

t_color	*normalize_colors(t_color *intensity_rgb)
{
	if (intensity_rgb->red > 1)
		intensity_rgb->red = 1;
	if (intensity_rgb->green > 1)
		intensity_rgb->green = 1;
	if (intensity_rgb->blue > 1)
		intensity_rgb->blue = 1;
	return (intensity_rgb);
}

float	color_switcher(int i, t_point *p, t_point *l)
{
	if (g_scene->lights[i]->type == 'p')
	{
		*l = point_minus_stack(g_scene->lights[i]->vect, p);
		return (1.f - EPS);
	}
	else
	{
		*l = point_copy_stack(g_scene->lights[i]->vect);
		point_mul_num(l, -1);
		return (INF);
	}
}
