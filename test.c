/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:16:10 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:06 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ray_traycer.h"

int 	camera(t_camera_input *inp, t_camera **dest)
{
	t_camera	*new_camera;

	new_camera = (t_camera *)malloc(sizeof(t_camera));
	if (!new_camera)
		return (1 + ft_free(inp->o) + ft_free(inp->view_vector));
	new_camera->fovx = 2.f * tanf(inp->fovx * PI / 360.f) / g_scene->res_x;
	new_camera->fovy = 2.f * tanf(inp->fovy * (float)g_scene->res_y
			 / (float)g_scene->res_x * PI / 360.f) / (float)g_scene->res_y;
	set_angles(new_camera, inp->view_vector);
	new_camera->gamma = 0;
	new_camera->o = inp->o;
	new_camera->view_vector = inp->view_vector;
	new_camera->rotation_matrix = (t_matrix3 *)malloc(sizeof(t_matrix3));
	if (!new_camera->rotation_matrix)
		return (1 + ft_free(inp->o) + ft_free(inp->view_vector));
	rotate_matrix(new_camera->rotation_matrix, new_camera->alpha,
		new_camera->theta, new_camera->gamma);
	*dest = new_camera;
	return (0);
}

void	set_angles(t_camera *new_camera, t_point *view_vector)
{
	if (fabsf(view_vector->x) + fabsf(view_vector->z) < EPS)
	{
		new_camera->alpha = 0;
		new_camera->theta = -significandf(view_vector->y) * PI_HALF;
	}
	else
	{
		new_camera->alpha = -atanf(-view_vector->x / view_vector->z);
		if (view_vector->z < 0)
			new_camera->alpha += PI;
		new_camera->theta = -atanf(view_vector->y
				/ sqrtf(view_vector->x * view_vector->x
					+ view_vector->z * view_vector->z));
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:33:09 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:09 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	circle(t_circle_input *inp, t_circle **dest)
{
	t_circle	*new_circle;

	*dest = NULL;
	new_circle = (t_circle *) malloc (sizeof(t_circle));
	if (!new_circle)
		return (ft_free(inp->center) + ft_free(inp->normal));
	*dest = new_circle;
	new_circle->center = inp->center;
	new_circle->normal = inp->normal;
	normalize(inp->normal);
	new_circle->r_sq = inp->radius * inp->radius;
	new_circle->color = inp->col;
	new_circle->specular = inp->specular;
	new_circle->reflective = inp->reflective;
	return (0);
}

int	circle_append(t_cylinder_input *i)
{
	t_circle_input	inp_ci;

	if (ft_append_array((void ***)&g_scene->circles, g_scene->circles_num,
			sizeof(t_circle *)))
		return (1);
	inp_ci.center = point(i->center->x + i->h * i->vec->x, i->center->y + i->h
			* i->vec->y, i->center->z + i->h * i->vec->z);
	inp_ci.normal = point(i->vec->x, i->vec->y, i->vec->z);
	if (!inp_ci.center || !inp_ci.normal)
		return (ft_free(inp_ci.center) + ft_free(inp_ci.normal) + 1);
	masf2(&inp_ci.radius, i->d / 2, &inp_ci.reflective, i->reflective);
	masi2(&inp_ci.specular, i->specular, (int *)&inp_ci.col, (int)i->col);
	if (circle(&inp_ci, g_scene->circles + g_scene->circles_num++))
		return (1);
	if (ft_append_array((void ***)&g_scene->circles, g_scene->circles_num,
			sizeof(t_circle *)))
		return (1);
	inp_ci.center = point(i->center->x - i->h * i->vec->x, i->center->y - i->h
			* i->vec->y, i->center->z - i->h * i->vec->z);
	inp_ci.normal = point(i->vec->x, i->vec->y, i->vec->z);
	if (!inp_ci.center || !inp_ci.normal)
		return (ft_free(inp_ci.center) + ft_free(inp_ci.normal) + 1);
	if (circle(&inp_ci, g_scene->circles + g_scene->circles_num++))
		return (1);
	return (0);
}

float	intersect_circle(t_point *o, t_point *d, t_circle *circle)
{
	t_point		co;
	float		dt;
	t_point		pc;
	float		ret;

	dt = dot(d, circle->normal);
	if (dt == 0)
		return (INF);
	co = point_minus_stack(circle->center, o);
	ret = dot(&co, circle->normal) / dt;
	if (ret < 0)
		return (INF);
	pc = point_stack(o->x + ret * d->x - circle->center->x, o->y + ret * d->y
			- circle->center->y, o->z + ret * d->z - circle->center->z);
	if (dot(&pc, &pc) > circle->r_sq)
		return (INF);
	return (ret);
}

float	closest_intersection_circle(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	int		i;
	float	inter;

	i = 0;
	while (i < g_scene->circles_num)
	{
		inter = intersect_circle(o, d, g_scene->circles[i]);
		if (inter >= t->t_min && inter <= t->t_max && inter < closest_object->t)
		{
			closest_object->t = inter;
			closest_object->id = 5;
			closest_object->obj = g_scene->circles[i];
		}
		i++;
	}
	return (closest_object->t);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:41:33 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:14 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

void	ft_clean_scene(void)
{
	if (!g_scene)
		return ;
	free(g_scene->img);
	free_spheres(g_scene->spheres, g_scene->spheres_num);
	free_planes(g_scene->planes, g_scene->planes_num);
	free_triangles(g_scene->triangles, g_scene->triangles_num);
	free_squares(g_scene->squares, g_scene->squares_num);
	free_cylinders(g_scene->cylinders, g_scene->cylinders_num);
	free_circles(g_scene->circles, g_scene->circles_num);
	free_lights(g_scene->lights, g_scene->lights_num);
	free_cameras(g_scene->cameras, g_scene->cameras_num);
	free(g_scene);
	g_scene = NULL;
}

void	free_spheres(t_sphere **sp, int num)
{
	while (num)
	{
		free(sp[num - 1]->center);
		free(sp[num - 1]);
		num--;
	}
	free(sp);
}

void	free_planes(t_plane **pl, int num)
{
	while (num)
	{
		free(pl[num - 1]->point);
		free(pl[num - 1]->normal);
		free(pl[num - 1]);
		num--;
	}
	free(pl);
}

void	free_triangles(t_triangle **tr, int num)
{
	while (num)
	{
		free(tr[num - 1]->normal);
		free(tr[num - 1]->a);
		free(tr[num - 1]->b);
		free(tr[num - 1]->c);
		free(tr[num - 1]->ab);
		free(tr[num - 1]->bc);
		free(tr[num - 1]->ca);
		free(tr[num - 1]);
		num--;
	}
	free(tr);
}

void	free_squares(t_square **sq, int num)
{
	while (num)
	{
		free(sq[num - 1]->center);
		free(sq[num - 1]->normal);
		free(sq[num - 1]->v1);
		free(sq[num - 1]->v2);
		free(sq[num - 1]);
		num--;
	}
	free(sq);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:41:54 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:16 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

void	free_cylinders(t_cylinder **cy, int num)
{
	while (num)
	{
		free(cy[num - 1]->center);
		free(cy[num - 1]->q);
		free(cy[num - 1]);
		num--;
	}
	free(cy);
}

void	free_circles(t_circle **cr, int num)
{
	while (num)
	{
		free(cr[num - 1]->center);
		free(cr[num - 1]->normal);
		free(cr[num - 1]);
		num--;
	}
	free(cr);
}

void	free_lights(t_light **li, int num)
{
	while (num)
	{
		free(li[num - 1]->color);
		free(li[num - 1]->vect);
		free(li[num - 1]);
		num--;
	}
	free(li);
}

void	free_cameras(t_camera **cam, int num)
{
	while (num)
	{
		free(cam[num - 1]->o);
		free(cam[num - 1]->view_vector);
		free(cam[num - 1]->rotation_matrix);
		free(cam[num - 1]);
		num--;
	}
	free(cam);
}

int	ft_close_window(int code, void	*_)
{
	(void)code;
	(void)_;
	mlx_destroy_image(g_scene->mlx, g_scene->img->img);
	mlx_destroy_window(g_scene->mlx, g_scene->mlx_win);
	ft_clean_scene();
	exit(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:01:56 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:19 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

t_color	*color(float red, float green, float blue, float intensity)
{
	t_color	*new_color;

	new_color = (t_color *) malloc (sizeof(t_color));
	if (!new_color)
		return (NULL);
	new_color->red = red * intensity;
	new_color->green = green * intensity;
	new_color->blue = blue * intensity;
	return (new_color);
}

t_color	color_stack(float red, float green, float blue, float intensity)
{
	t_color	new_color;

	new_color.red = red * intensity;
	new_color.green = green * intensity;
	new_color.blue = blue * intensity;
	return (new_color);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:11:06 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:22 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	color_plmul_color(t_color *p, t_color *to_sum, float to_mul)
{
	p->red += to_sum->red * to_mul;
	p->green += to_sum->green * to_mul;
	p->blue += to_sum->blue * to_mul;
	return (1);
}

unsigned int	color_mul(unsigned int col, float alpha)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;

	blue = col & BLUE;
	green = (col & GREEN) >> 8u;
	red = (col & RED) >> 16u;
	blue = (unsigned)((float)blue * alpha);
	green = (unsigned)((float)green * alpha);
	red = (unsigned)((float)red * alpha);
	return (blue | (green << 8u) | (red << 16u));
}

unsigned int	color_mul_rgb(unsigned int col, t_color *alpha)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;

	blue = col & BLUE;
	green = (col & GREEN) >> 8u;
	red = (col & RED) >> 16u;
	blue = (unsigned)floorf(((float)blue * alpha->blue) + 0.5f);
	green = (unsigned)floorf(((float)green * alpha->green) + 0.5f);
	red = (unsigned)floorf(((float)red * alpha->red) + 0.5f);
	return (blue | (green << 8u) | (red << 16u));
}

unsigned int	color_sum(unsigned int col1, unsigned int col2)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;

	blue = (col1 & BLUE) + (col2 & BLUE);
	green = ((col1 & GREEN) >> 8u) + ((col2 & GREEN) >> 8u);
	red = ((col1 & RED) >> 16u) + ((col2 & RED) >> 16u);
	blue = ft_min((int)blue, 255);
	green = ft_min((int)green, 255);
	red = ft_min((int)red, 255);
	return (blue | (green << 8u) | (red << 16u));
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:33:29 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:29 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	cylinder(t_cylinder_input *inp, t_cylinder **dest)
{
	t_cylinder		*new_cylinder;

	*dest = NULL;
	new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		return (ft_free(inp->center) + ft_free(inp->vec) + 1);
	*dest = new_cylinder;
	new_cylinder->center = inp->center;
	new_cylinder->q = inp->vec;
	normalize(inp->vec);
	new_cylinder->r_sq = inp->d / 2;
	new_cylinder->r_sq = new_cylinder->r_sq * new_cylinder->r_sq;
	inp->h /= 2;
	new_cylinder->h_half = inp->h;
	new_cylinder->color = inp->col;
	new_cylinder->specular = inp->specular;
	new_cylinder->reflective = inp->reflective;
	if (circle_append(inp))
		return (1);
	return (0);
}

t_pair	intersect_cylinder(t_point *o, t_point *d, t_cylinder *cylinder,
	float t_min)
{
	float		dts[3];
	t_point		pa[5];
	float		c[3];

	pa[2] = point_minus_stack(o, cylinder->center);
	pa[0] = point_cross_stack(&pa[2], cylinder->q);
	pa[1] = point_cross_stack(d, cylinder->q);
	c[0] = 2.f * dot(pa + 1, pa + 1);
	c[1] = -2.f * dot(pa, pa + 1);
	c[2] = dot(pa, pa) - cylinder->r_sq;
	dts[0] = c[1] * c[1] - 2.f * c[0] * c[2];
	if (dts[0] < 0)
		return ((t_pair){INF, INF});
	dts[0] = sqrtf(dts[0]);
	dts[1] = tern_f(c[1] > 0 && dts[0] < c[1], (c[1] - dts[0]
				) / c[0], (c[1] + dts[0]) / c[0]);
	if (dts[1] <= t_min)
		dts[1] = (c[1] + dts[0]) / c[0];
	pa[4] = point_stack(o->x + d->x * dts[1], o->y + d->y
			* dts[1], o->z + d->z * dts[1]);
	pa[3] = point_minus_stack(&pa[4], cylinder->center);
	dts[2] = dot(&pa[3], cylinder->q);
	if (fabsf(dts[2]) > cylinder->h_half)
		return ((t_pair){INF, INF});
	return ((t_pair){dts[1], dts[2]});
}

float	closest_intersection_cylinder(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	t_pair		inter;
	int			i;

	i = 0;
	while (i < g_scene->cylinders_num)
	{
		inter = intersect_cylinder(o, d, g_scene->cylinders[i], t->t_min);
		if (inter.t_min >= t->t_min && inter.t_min <= t->t_max && inter.t_min
			< closest_object->t)
		{
			closest_object->t = inter.t_min;
			closest_object->id = 4;
			closest_object->obj = g_scene->cylinders[i];
			closest_object->normal.x = g_scene->cylinders[i]->center->x
				+ g_scene->cylinders[i]->q->x * inter.t_max;
			closest_object->normal.y = g_scene->cylinders[i]->center->y
				+ g_scene->cylinders[i]->q->y * inter.t_max;
			closest_object->normal.z = g_scene->cylinders[i]->center->z
				+ g_scene->cylinders[i]->q->z * inter.t_max;
		}
		i++;
	}
	return (closest_object->t);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switcher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:57:28 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:34 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

#define MOVE_STEP 0.5f
#define LOOK_ANGLE 0.157079632675f

int	key_switcher_1(int keycode, t_point *n)
{
	if (keycode == 65431)
	{
		g_scene->current_camera->alpha -= LOOK_ANGLE
			* sinf(g_scene->current_camera->gamma);
		g_scene->current_camera->theta -= LOOK_ANGLE
			* cosf(g_scene->current_camera->gamma);
		return (0);
	}
	else if (keycode == 65433)
	{
		g_scene->current_camera->alpha += LOOK_ANGLE
			* sinf(g_scene->current_camera->gamma);
		g_scene->current_camera->theta += LOOK_ANGLE
			* cosf(g_scene->current_camera->gamma);
		return (0);
	}
	else if (keycode == 119)
	{
		*n = point_stack(0, 0, MOVE_STEP);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else
		return (key_switcher_2(keycode, n));
}

int	key_switcher_2(int keycode, t_point *n)
{
	if (keycode == 65432)
	{
		g_scene->current_camera->alpha += LOOK_ANGLE
			* cosf(g_scene->current_camera->gamma);
		g_scene->current_camera->theta -= LOOK_ANGLE
			* sinf(g_scene->current_camera->gamma);
		return (0);
	}
	else if (keycode == 65430)
	{
		g_scene->current_camera->alpha -= LOOK_ANGLE
			* cosf(g_scene->current_camera->gamma);
		g_scene->current_camera->theta += LOOK_ANGLE
			* sinf(g_scene->current_camera->gamma);
		return (0);
	}
	else if (keycode == 115)
	{
		*n = point_stack(0, 0, -MOVE_STEP);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else
		return (key_switcher_3(keycode, n));
}

int	key_switcher_3(int keycode, t_point *n)
{
	if (keycode == 97)
	{
		*n = point_stack(-MOVE_STEP, 0, 0);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else if (keycode == 100)
	{
		*n = point_stack(MOVE_STEP, 0, 0);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else if (keycode == 32)
	{
		*n = point_stack(0, MOVE_STEP, 0);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else
	{
		return (key_switcher_4(keycode, n));
	}
}

int	key_switcher_4(int keycode, t_point *n)
{
	if (keycode == 65507)
	{
		*n = point_stack(0, -MOVE_STEP, 0);
		matrix3_mul(g_scene->current_camera->rotation_matrix, n);
		point_plus_point(g_scene->current_camera->o, n);
		return (0);
	}
	else if (keycode == 113)
	{
		g_scene->current_camera->gamma += LOOK_ANGLE;
		return (0);
	}
	else if (keycode == 101)
	{
		g_scene->current_camera->gamma -= LOOK_ANGLE;
		return (0);
	}
	if (keycode == 65307)
	{
		ft_close_window(0, NULL);
		return (1);
	}
	else
		return (key_switcher_5(keycode));
}

int	key_switcher_5(int keycode)
{
	if (keycode == 99 && g_scene->cameras_num > 1)
	{
		g_scene->current_camera_num++;
		g_scene->current_camera_num %= g_scene->cameras_num;
		g_scene->current_camera = g_scene->cameras[g_scene->current_camera_num];
		return (0);
	}
	else if (keycode != 112 && keycode != 0)
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:33:38 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:38 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	key_hook(int keycode, void *_)
{
	t_point	n;

	(void)_;
	if (key_switcher_1(keycode, &n))
		return (0);
	rotate_matrix(g_scene->current_camera->rotation_matrix, g_scene
		->current_camera->alpha, g_scene->current_camera
		->theta, g_scene->current_camera->gamma);
	minirt_loop();
	if (keycode == 112)
		return (screenshot("/media/kostya/D/Clion/Linux/MiniRT/MiniRT/"
				"scr.bmp"));
	mlx_put_image_to_window(g_scene->mlx, g_scene->mlx_win, g_scene->img->img,
		0, 0);
	return (0);
}

void	minirt_loop(void)
{
	t_pair	t_min_max;
	t_point	d;
	int		x;
	int		y;

	t_min_max.t_min = 1;
	t_min_max.t_max = INF;
	x = -g_scene->res_x / 2;
	while (x < g_scene->res_x / 2)
	{
		y = -g_scene->res_y / 2;
		while (y < g_scene->res_y / 2)
		{
			d = (t_point){(float) x * g_scene->current_camera->fovx, (float) y
				* g_scene->current_camera->fovy, g_scene->dist};
			matrix3_mul(g_scene->current_camera->rotation_matrix, &d);
			unsigned color = trace_ray(g_scene->current_camera->o, &d,
					&t_min_max, 1);
			put_pixel(g_scene->img, x, -y, color);
			y++;
		}
		x++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:01:21 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	light(t_light_input *inp, t_light **dest)
{
	t_light	*new_light;

	*dest = NULL;
	new_light = (t_light *) malloc (sizeof(t_light));
	if (!new_light)
		return (ft_free(inp->rgb) + ft_free(inp->vect) + 1);
	new_light->type = inp->type;
	new_light->color = inp->rgb;
	new_light->vect = inp->vect;
	if (inp->type == 'd')
		normalize(inp->vect);
	*dest = new_light;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:10:06 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:44 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (ft_exit_all("No input file"));
	if (init_scene() || check_extention(argv[1]))
		return (0);
	g_scene->dist = 1.f + EPS;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("cannot open ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" file\n", 1);
		return (0);
	}
	g_scene->mlx = mlx_init();
	if (g_scene->mlx == NULL)
		return (0 * ft_exit_all("mlx error"));
	if (parce_scene(fd))
	{
		close(fd);
		return (0);
	}
	return (main_1(argc, argv));
}

int	do_screenshot(int argc, char **argv)
{
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		g_scene->img = (t_data *) malloc(sizeof(t_data *));
		if (!g_scene->img)
			return (ft_exit_all("malloc error"));
		g_scene->img->addr = (unsigned *) malloc(g_scene->res_x
				* g_scene->res_y * 32);
		if (!g_scene->img->addr)
			return (ft_exit_all("malloc error"));
		g_scene->img->bits_per_pixel = 32;
		g_scene->img->line_length = g_scene->res_x * 4;
		if (key_hook(112, NULL))
			return (ft_exit_all("cannot open file"));
		ft_clean_scene();
		return (1);
	}
	return (0);
}

int	main_1(int argc, char **argv)
{
	if (g_scene->res_x < 0 || g_scene->res_y < 0)
		return (0 * ft_exit_all("resolution not set"));
	if (g_scene->cameras_num == 0)
		return (0 * ft_exit_all("no cameras in scene"));
	if (do_screenshot(argc, argv))
		return (0);
	g_scene->img = (t_data *)malloc(sizeof(t_data));
	if (!g_scene->img)
		return (0 * ft_exit_all("malloc error"));
	g_scene->mlx_win = mlx_new_window(g_scene->mlx, g_scene->res_x, g_scene
			->res_y, "MiniRT");
	g_scene->img->img = mlx_new_image(g_scene->mlx, g_scene->res_x, g_scene
			->res_y);
	g_scene->img->addr = (unsigned *)mlx_get_data_addr(g_scene->img->img,
			&g_scene->img->bits_per_pixel,
			&g_scene->img->line_length, &g_scene->img->endian);
	mlx_put_image_to_window(g_scene->mlx, g_scene->mlx_win, g_scene->img->img,
		0, 0);
	mlx_hook(g_scene->mlx_win, 33, 0, ft_close_window, NULL);
	mlx_key_hook(g_scene->mlx_win, key_hook, NULL);
	key_hook(0, NULL);
	mlx_loop(g_scene->mlx);
	return (0);
}

int	check_extention(char *fname)
{
	int	size;

	size = ft_strlen(fname);
	if (size < 3 || fname[size - 3] != '.' || fname[size - 2] != 'r'
		|| fname[size - 1] != 't')
	{
		ft_putstr_fd(ERROR "Error" RESET, 1);
		ft_putstr_fd("\nwrong file name/extention\n", 1);
		return (1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:44:29 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:53 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

float	triple_product(t_point *n, t_point *a, t_point *p, t_point *v)
{
	return (
		v->x * (n->y * (p->z - a->z) - n->z * (p->y - a->y))
		- v->y * (n->x * (p->z - a->z) - n->z * (p->x - a->x))
		+ v->z * (n->x * (p->y - a->y) - n->y * (p->x - a->x))
	);
}

float	q_rsqrt(float number)
{
	unsigned long	i;
	float			x2;
	float			y;
	void			*ptr;

	x2 = number * 0.5f;
	y = number;
	ptr = &y;
	i = *(unsigned long *)ptr;
	i = 0x5f3759df - (i >> 1u);
	ptr = &i;
	y = *(float *)ptr;
	y = y * (1.5f - (x2 * y * y));
	y = y * (1.5f - (x2 * y * y));
	return (y);
}
#include "ray_traycer.h"

void	rotate_matrix(t_matrix3 *matr, float alpha, float theta, float gamma)
{
	float	__sin[3];
	float	__cos[3];

	sincosf(alpha, __sin, __cos);
	sincosf(theta, __sin + 1, __cos + 1);
	(void)gamma;
	matr->a11 = __cos[0];
	matr->a12 = __sin[0] * __sin[1];
	matr->a13 = __sin[0] * __cos[1];
	matr->a21 = 0;
	matr->a22 = __cos[1];
	matr->a23 = -__sin[1];
	matr->a31 = -__sin[0];
	matr->a32 = __sin[1] * __cos[0];
	matr->a33 = __cos[0] * __cos[1];
}

void	rotate_matrix_gamma(t_matrix3 *matr, float alpha, float theta,
	float gamma)
{
	float	__sin[3];
	float	__cos[3];

	sincosf(alpha, __sin, __cos);
	sincosf(theta, __sin + 1, __cos + 1);
	sincosf(gamma, __sin + 2, __cos + 2);
	matr->a11 = __cos[2] * __cos[0];
	matr->a12 = -__sin[2] * __cos[0];
	matr->a13 = __sin[0];
	matr->a21 = __sin[1] * __sin[0] * __cos[2] + __sin[2] * __cos[1];
	matr->a22 = -__sin[1] * __sin[2] * __sin[0] + __cos[1] * __cos[2];
	matr->a23 = -__sin[1] * __cos[0];
	matr->a31 = __sin[1] * __sin[2] - __sin[0] * __cos[0] * __cos[1] * __cos[2];
	matr->a32 = __sin[1] * __cos[2] + __sin[2] * __sin[0] * __cos[1];
	matr->a33 = __cos[1] * __cos[0];
}

void	matrix3_mul(t_matrix3 *matr, t_point *vect)
{
	float	dx;
	float	dy;
	float	dz;

	dx = matr->a11 * vect->x + matr->a12 * vect->y + matr->a13 * vect->z;
	dy = matr->a21 * vect->x + matr->a22 * vect->y + matr->a23 * vect->z;
	dz = matr->a31 * vect->x + matr->a32 * vect->y + matr->a33 * vect->z;
	vect->x = dx;
	vect->y = dy;
	vect->z = dz;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiassignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:17:03 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	masi2(int *dest1, int source1, int *dest2, int source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}

int	masp2(t_point **dest1, t_point *source1, t_point **dest2, t_point *source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}

int	masp1(t_point **dest, t_point *source)
{
	*dest = source;
	return (1);
}

int	masf2(float *dest1, float source1, float *dest2, float source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:34:13 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:34:26 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	plane(t_plane_input *inp, t_plane **dest)
{
	t_plane	*new_plane;

	*dest = NULL;
	new_plane = (t_plane *)malloc(sizeof(t_plane));
	if (!new_plane)
		return (ft_free(inp->p) + ft_free(inp->normal) + 1);
	new_plane->point = inp->p;
	new_plane->normal = inp->normal;
	normalize(inp->normal);
	new_plane->color = inp->col;
	new_plane->specular = inp->specular;
	new_plane->reflective = inp->reflective;
	*dest = new_plane;
	return (0);
}

float	intersect_plane(t_point *o, t_point *d, t_plane *plane)
{
	t_point		co;
	float		dt;
	float		ret;

	dt = dot(d, plane->normal);
	if (dt == 0)
		return (INF);
	co = point_minus_stack(plane->point, o);
	ret = dot(&co, plane->normal) / dt;
	if (ret < 0)
		return (INF);
	return (ret);
}

float	closest_intersection_plane(t_point *o, t_point *d, t_pair *t, t_object
	*closest_object)
{
	int		i;
	float	inter;

	i = 0;
	while (i < g_scene->planes_num)
	{
		inter = intersect_plane(o, d, g_scene->planes[i]);
		if (inter >= t->t_min && inter <= t->t_max && inter < closest_object->t)
		{
			closest_object->t = inter;
			closest_object->id = 1;
			closest_object->obj = g_scene->planes[i];
		}
		i++;
	}
	return (closest_object->t);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:51:42 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:34:32 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

t_point	*point(float x, float y, float z)
{
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}

t_point	*point_minus(t_point *p1, t_point *p2)
{
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = p1->x - p2->x;
	new_point->y = p1->y - p2->y;
	new_point->z = p1->z - p2->z;
	return (new_point);
}

t_point	*point_plus(t_point *p1, t_point *p2)
{
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = p1->x + p2->x;
	new_point->y = p1->y + p2->y;
	new_point->z = p1->z + p2->z;
	return (new_point);
}

t_point	*point_cross(t_point *p1, t_point *p2)
{
	t_point		*new_point;

	new_point = (t_point *)malloc(sizeof(t_point *));
	if (!new_point)
		return (NULL);
	new_point->x = det2(p1->y, p1->z, p2->y, p2->z);
	new_point->y = -(det2(p1->x, p1->z, p2->x, p2->z));
	new_point->z = det2(p1->x, p1->y, p2->x, p2->y);
	return (new_point);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:58:03 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:34:37 by tlucanti         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parcer_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:44:35 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/22 12:26:43 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	init_scene(void)
{
	g_scene = (t_scene *)malloc(sizeof(t_scene));
	if (g_scene == NULL)
		return (ft_exit_all("Malloc error"));
	g_scene->res_x = -1;
	g_scene->res_y = -1;
	g_scene->cameras_num = 0;
	g_scene->spheres_num = 0;
	g_scene->planes_num = 0;
	g_scene->triangles_num = 0;
	g_scene->squares_num = 0;
	g_scene->circles_num = 0;
	g_scene->cylinders_num = 0;
	g_scene->lights_num = 0;
	g_scene->cameras = NULL;
	g_scene->spheres = NULL;
	g_scene->planes = NULL;
	g_scene->triangles = NULL;
	g_scene->squares = NULL;
	g_scene->circles = NULL;
	g_scene->cylinders = NULL;
	g_scene->lights = NULL;
	return (0);
}

int	parce_scene(int fd)
{
	char	*line;
	int		ret;
	char	**splt;
	int		gnl;

	gnl = get_next_line(fd, &line);
	while (gnl != -1)
	{
		splt = ft_split(line, ft_isspace);
		if (!splt)
			return (ft_exit_all("Malloc error"));
		ret = switcher(splt);
		ft_line_free(splt);
		free(line);
		if (ret)
			return (1);
		if (gnl == 0)
			return (0);
		gnl = get_next_line(fd, &line);
	}
	return (ft_exit_all("File read or malloc error"));
}

int	switcher(char **splt)
{
	if (!*splt || **splt == '#')
		return (0);
	else if (!ft_strcmp(*splt, "R") || !ft_strcmp(*splt, "r"))
		return (ft_set_resolution(splt));
	else if (!ft_strcmp(*splt, "A") || !ft_strcmp(*splt, "a"))
		return (ft_add_ambient(splt));
	else if (!ft_strcmp(*splt, "c"))
		return (ft_add_camera(splt));
	else if (!ft_strcmp(*splt, "l"))
		return (ft_add_point(splt));
	else if (!ft_strcmp(*splt, "sp"))
		return (ft_add_sphere(splt));
	else if (!ft_strcmp(*splt, "pl"))
		return (ft_add_plane(splt));
	else if (!ft_strcmp(*splt, "sq"))
		return (ft_add_square(splt));
	else if (!ft_strcmp(*splt, "cy"))
		return (ft_add_cylinder(splt));
	else if (!ft_strcmp(*splt, "tr"))
		return (ft_add_triangle(splt));
	else if (!ft_strcmp(*splt, "d"))
		return (ft_add_direct(splt));
	return (0);
}

int	ft_set_resolution(char **line)
{
	int	max_x;
	int	max_y;

	if (ft_array_size(line) < 3)
		return (ft_exit_all("Incorrect resolution configuration"));
	g_scene->res_x = ft_atoi(line[1]);
	g_scene->res_y = ft_atoi(line[2]);
	mlx_get_screen_size(g_scene->mlx, &max_x, &max_y);
	g_scene->res_x = ft_min(max_x, g_scene->res_x);
	g_scene->res_y = ft_min(max_y, g_scene->res_y);
	if (ft_check_rangei(g_scene->res_x, 1, 0x7fffffff, "resolution")
		|| ft_check_rangei(g_scene->res_y, 1, 0x7fffffff, "resolution"))
		return (1);
	return (0);
}

int	ft_add_ambient(char **line)
{
	t_light_input	inp;
	size_t			size;

	size = ft_array_size(line);
	if (size < 2)
		return (ft_exit_all("Incorrect ambient light configuration"));
	inp.type = 'a';
	inp.intensity = ft_atof(line[1]);
	if (size < 3)
		inp.rgb = color(1, 1, 1, inp.intensity);
	else
		inp.rgb = color_str_struct(line[2], inp.intensity);
	inp.vect = NULL;
	if (!inp.rgb || ft_check_rangef(inp.intensity, 0, 1,
			"ambient light intensity"))
		return (1);
	if (ft_append_array((void ***) &g_scene->lights, g_scene->lights_num,
			sizeof(t_light *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.rgb));
	if (light(&inp, g_scene->lights + g_scene->lights_num++))
		return (ft_exit_all("Malloc error"));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parcer_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:55 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:34:54 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	ft_add_camera(char **line)
{
	t_camera_input	inp;

	if (ft_array_size(line) < 4)
		return (ft_exit_all("Incorrect camera configuration"));
	inp.o = point_str(line[1]);
	inp.view_vector = point_str(line[2]);
	inp.fovx = ft_atof(line[3]);
	inp.fovy = inp.fovx;
	if (!inp.o || !inp.view_vector
		|| ft_check_rangef(inp.fovx, 0, 180, "fov"))
		return (ft_free(inp.o) + ft_free(inp.view_vector) + 1);
	if (ft_append_array((void ***)&g_scene->cameras, g_scene->cameras_num,
			sizeof(t_camera *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.o)
			+ ft_free(inp.view_vector));
	if (camera(&inp, g_scene->cameras + g_scene->cameras_num++))
		return (ft_exit_all("Maloc error"));
	ft_normalize_vect(inp.view_vector, "camera view");
	g_scene->current_camera = g_scene->cameras[0];
	g_scene->current_camera_num = 0;
	return (0);
}

int	ft_add_point(char **line)
{
	t_light_input	inp;
	size_t			size;

	size = ft_array_size(line);
	if (size < 3)
		return (ft_exit_all("Incorrect point light configuration"));
	inp.type = 'p';
	inp.intensity = ft_atof(line[2]);
	if (size > 3)
		inp.rgb = color_str_struct(line[3], inp.intensity);
	else
		inp.rgb = color(1, 1, 1, inp.intensity);
	inp.vect = point_str(line[1]);
	if (!inp.rgb || !inp.vect || ft_check_rangef(inp.intensity, 0, 1,
			"point light intensity"))
		return (ft_free(inp.rgb) + ft_free(inp.vect) + 1);
	if (ft_append_array((void ***) &g_scene->lights, g_scene->lights_num,
			sizeof(t_light *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.rgb)
			+ ft_free(inp.vect));
	if (light(&inp, g_scene->lights + g_scene->lights_num++))
		return (ft_exit_all("Malloc error"));
	return (0);
}

int	ft_add_direct(char **line)
{
	t_light_input	inp;
	size_t			size;

	size = ft_array_size(line);
	if (size < 3)
		return (ft_exit_all("Incorrect point light configuration"));
	inp.type = 'd';
	inp.intensity = ft_atof(line[2]);
	if (size > 3)
		inp.rgb = color_str_struct(line[3], inp.intensity);
	else
		inp.rgb = color(1, 1, 1, inp.intensity);
	inp.vect = point_str(line[1]);
	if (!inp.rgb || !inp.vect)
		return (ft_free(inp.rgb), ft_free(inp.vect));
	if (ft_append_array((void ***) &g_scene->lights, g_scene->lights_num,
			sizeof(t_light *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.rgb)
			+ ft_free(inp.vect));
	if (light(&inp, g_scene->lights + g_scene->lights_num++))
		return (ft_exit_all("Malloc error"));
	ft_normalize_vect(inp.vect, "direct light");
	return (0);
}

int	ft_add_sphere( char **line)
{
	t_sphere_input	inp;
	int				size;

	size = ft_array_size(line);
	if (size < 4)
		return (ft_exit_all("Incorrect sphere configuration"));
	inp.center = point_str(line[1]);
	inp.radius = ft_atof(line[2]);
	inp.col = color_str(line[3]);
	inp.specular = 200;
	if (size >= 5)
		inp.specular = ft_atoi(line[4]);
	inp.reflective = -1.f;
	if (size >= 6)
		inp.reflective = ft_atof(line[5]);
	if (!inp.center || !inp.radius || inp.col == 0xffffffff
		|| ft_check_rangef(inp.reflective, 0xffffffff, 1, "sphere reflective")
		|| ft_check_rangef(inp.radius, 0, 0x7fffffff, "sphere radius"))
		return (1 + ft_free(inp.center));
	if (ft_append_array((void ***) &g_scene->spheres, g_scene->spheres_num,
			sizeof(t_sphere *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.center));
	if (sphere(&inp, g_scene->spheres + g_scene->spheres_num++))
		return (ft_exit_all("Malloc error"));
	return (0);
}

int	ft_add_plane(char **line)
{
	t_plane_input	inp;
	int				size;

	size = ft_array_size(line);
	if (size < 4)
		return (ft_exit_all("Incorrect plane configuration"));
	inp.p = point_str(line[1]);
	inp.normal = point_str(line[2]);
	inp.col = color_str(line[3]);
	inp.specular = tern_atoi(size >= 5, 200, line[4]);
	inp.reflective = tern_atof(size >= 6, -1.f, line[6]);
	if (!inp.p || !inp.normal || inp.col == 0xffffffff
		|| ft_check_rangef(inp.reflective, 0xffffffff, 1, "plane reflective"))
		return (1 + ft_free(inp.p) + ft_free(inp.normal));
	if (ft_append_array((void ***) &g_scene->planes, g_scene->planes_num,
			sizeof(t_plane *)))
		return (ft_exit_all("Malloc error")
			+ ft_free(inp.p) + ft_free(inp.normal));
	if (plane(&inp, g_scene->planes + g_scene->planes_num++))
		return (ft_exit_all("Malloc error"));
	ft_normalize_vect(inp.normal, "plane normal");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parcer_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:03:08 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/22 12:42:47 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	ft_add_square(char **line)
{
	t_square_input	inp;
	int				size;

	size = ft_array_size(line);
	if (size < 5)
		return (ft_exit_all("Incorrect square configuration"));
	inp.center = point_str(line[1]);
	inp.normal = point_str(line[2]);
	inp.d = ft_atof(line[3]);
	inp.col = color_str(line[4]);
	inp.specular = tern_atoi(size >= 6, 200, line[5]);
	inp.reflective = tern_atof(size >= 7, -1.f, line[6]);
	if (!inp.center || !inp.normal || inp.col == 0xffffffff
		|| ft_check_rangef(inp.d, 0, 0x7fffffff, "square side size")
		|| ft_check_rangef(inp.reflective, 0xffffffff, 1, "square reflective"))
		return (1 + ft_free(inp.center) + ft_free(inp.normal));
	if (ft_append_array((void ***) &g_scene->squares, g_scene->squares_num,
			sizeof(t_square *)))
		return (ft_exit_all("Malloc error")
			+ ft_free(inp.center) + ft_free(inp.normal));
	if (square(&inp, g_scene->squares + g_scene->squares_num++))
		return (ft_exit_all("Malloc error"));
	ft_normalize_vect(inp.normal, "square normal");
	return (0);
}

int	ft_add_cylinder(char **line)
{
	t_cylinder_input	inp;
	int					size;

	size = ft_array_size(line);
	if (size < 6)
		return (ft_exit_all("Incorrect cylinder configuration"));
	inp.center = point_str(line[1]);
	inp.vec = point_str(line[2]);
	inp.col = color_str(line[3]);
	masf2(&inp.d, ft_atof(line[4]), &inp.h, ft_atof(line[5]));
	inp.specular = tern_atoi(size >= 7, 200, line[6]);
	inp.reflective = tern_atof(size >= 8, -1.f, line[7]);
	if (!inp.center || !inp.vec || inp.col == 0xffffffff
		|| ft_check_rangef(inp.d, 0, 0x7fffffff, "cylinder diameter")
		|| ft_check_rangef(inp.reflective, -1, 1, "cylinder reflective")
		|| ft_check_rangef(inp.h, 0, 0x7fffffff, "cylinder height"))
		return (1 + ft_free(inp.center) + ft_free(inp.vec));
	if (ft_append_array((void ***) &g_scene->cylinders, g_scene->cylinders_num,
			sizeof(t_cylinder *)))
		return (ft_exit_all("Malloc error") + ft_free(inp.center)
			+ ft_free(inp.vec));
	if (cylinder(&inp, g_scene->cylinders + g_scene->cylinders_num++))
		return (ft_exit_all("Malloc error"));
	ft_normalize_vect(inp.vec, "cylinder direction");
	return (0);
}

int	ft_add_triangle(char **line)
{
	t_triangle_input	inp;
	int					size;

	size = ft_array_size(line);
	if (size < 5)
		return (ft_exit_all("Incorrect triangle configuration"));
	inp.x = point_str(line[1]);
	inp.y = point_str(line[2]);
	inp.z = point_str(line[3]);
	inp.col = color_str(line[4]);
	inp.specular = tern_atoi(size >= 6, 200, line[5]);
	inp.reflective = tern_atof(size >= 7, -1.f, line[6]);
	if (!inp.x || !inp.y || !inp.z || inp.col == 0xffffffff
		|| ft_check_rangef(inp.reflective, -1, 1, "triangle reflective"))
		return (1 + ft_free(inp.x) + ft_free(inp.y) + ft_free(inp.z));
	if (ft_append_array((void ***) &g_scene->triangles, g_scene->triangles_num,
			sizeof(t_triangle *)))
		return (ft_exit_all("Malloc error")
			+ ft_free(inp.x) + ft_free(inp.y) + ft_free(inp.z));
	if (triangle(&inp, g_scene->triangles + g_scene->triangles_num++))
		return (ft_exit_all("Malloc error"));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parcer_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:00 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:02 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	ft_exit_all(char *message)
{
	ft_putstr_fd("Error\n", 1);
	if (message[0])
	{
		ft_putstr_fd(message, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_clean_scene();
	return (1);
}

t_color	*color_str_struct(char *line, float intensity)
{
	char		**splt;
	t_color		*col;
	int			rgb[3];

	splt = ft_split(line, ft_iscomma);
	if (!splt)
		return ((t_color *)(size_t)(0 * ft_exit_all("Malloc error")));
	if (ft_array_size(splt) != 3)
	{
		ft_line_free(splt);
		ft_exit_all("Incorrect color configuration");
		return (NULL);
	}
	rgb[0] = ft_atoi(splt[0]);
	rgb[1] = ft_atoi(splt[1]);
	rgb[2] = ft_atoi(splt[2]);
	ft_line_free(splt);
	if (ft_check_rangei(rgb[0], 0, 255, "red color") || ft_check_rangei(rgb[1],
			0, 255, "green color") || ft_check_rangei(rgb[2], 0, 255, "blue col"
			"or") || ft_check_rangef(intensity, 0, 1, "color intensity"))
		return (NULL);
	col = color(rgb[0] / 255.f, rgb[1] / 255.f, rgb[2] / 255.f, intensity);
	if (!col)
		return ((t_color *)(size_t)(0 * ft_exit_all("Malloc error")));
	return (col);
}

t_point	*point_str(char *line)
{
	char	**splt;
	t_point	*p;

	splt = ft_split(line, ft_iscomma);
	if (!splt)
	{
		ft_exit_all("Malloc error");
		return (NULL);
	}
	if (ft_array_size(splt) != 3)
	{
		ft_line_free(splt);
		ft_exit_all("Incorrect vector/point configuration");
		return (NULL);
	}
	p = point(ft_atof(splt[0]), ft_atof(splt[1]), ft_atof(splt[2]));
	ft_line_free(splt);
	if (!p)
	{
		ft_exit_all("Malloc error");
		return (NULL);
	}
	return (p);
}

unsigned int	color_str(char *line)
{
	char			**splt;
	int				rgb[3];

	splt = ft_split(line, ft_iscomma);
	if (!splt)
		return (ft_exit_all("Malloc error") * 0 - 1);
	if (ft_array_size(splt) != 3)
	{
		ft_line_free(splt);
		return (ft_exit_all("Incorrect color configuration") * 0 - 1);
	}
	rgb[0] = ft_atoi(splt[0]);
	rgb[1] = ft_atoi(splt[1]);
	rgb[2] = ft_atoi(splt[2]);
	ft_line_free(splt);
	if (ft_check_rangei(rgb[0], 0, 255, "color") || ft_check_rangei(rgb[1], 0,
			255, "color") || ft_check_rangei(rgb[2], 0, 255, "color"))
		return (-1);
	return (((unsigned)rgb[0] << 16u)
		| ((unsigned)rgb[1] << 8u) | (unsigned)rgb[2]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:05 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:12 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <z3.h>
#include "ray_traycer.h"

int	screenshot(const char *fname)
{
	int			fd;
	uint64_t	f_size;
	uint64_t	header[7];
	int			_;

	fd = open(fname, 101, 0644);
	if (fd == -1)
		return (1);
	ft_bzero(header, 56);
	f_size = 14 + 40 + (g_scene->res_x * g_scene->res_y) * 4;
	g_scene->res_y *= -1;
	header[0x00] = 0x4d42u | f_size << 16u;
	header[0x01] = 0x28000000380000u;
	header[0x02] = (uint64_t) g_scene->res_x << 16u | ((uint64_t)(short)g_scene
			->res_y) << 48u;
	header[0x03] = (unsigned) g_scene->res_y >> 16u | 0x2000010000u;
	_ = write(fd, header, 56);
	g_scene->res_y *= -1;
	_ += write(fd, g_scene->img->addr, g_scene->res_x * g_scene->res_y * 4);
	(void)_;
	close(fd);
	ft_putstr_fd("saved screenshot at ./scr.bmp\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:11:48 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:16 by tlucanti         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:19 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/22 13:02:38 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	square(t_square_input *inp, t_square **dest)
{
	t_square	*sq;

	*dest = NULL;
	sq = (t_square *)malloc(sizeof(t_square));
	if (!sq)
		return (ft_free(inp->center) + ft_free(inp->normal) + 1);
	*dest = sq;
	sq->center = inp->center;
	sq->normal = inp->normal;
	sq->color = inp->col;
	sq->specular = inp->specular;
	sq->reflective = inp->reflective;
	sq->d = inp->d / 2;
	sq->v1 = point(inp->normal->y, -inp->normal->x, 0);
	sq->v2 = point_cross(inp->normal, sq->v1);
	normalize(sq->normal);
	if (fabsf(sq->normal->z - 1.f) < EPS)
	{
		sq->v1 = point(0, 1, 0);
		sq->v2 = point(1, 0, 0);
	}
	if (!sq->v1 || !sq->v2)
		return (1);
	(void)(normalize(sq->v2) && normalize(sq->v1));
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:49:43 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:23 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"
float	tern_f(int cond, float tru, float flse)
{
	if (cond)
		return (tru);
	return (flse);
}

int	tern_i(int cond, int tru, int flse)
{
	return (cond * tru + !cond * flse);
}

int	tern_atoi(int cond, int flse, char *str)
{
	if (cond)
		return (ft_atoi(str));
	return (flse);
}

float	tern_atof(int cond, float flse, char *str)
{
	if (cond)
		return (ft_atof(str));
	return (flse);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:29 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:31 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	triangle(t_triangle_input *inp, t_triangle **dest)
{
	t_triangle	*nt;
	t_point		m1;
	t_point		m2;

	*dest = NULL;
	nt = (t_triangle *)malloc(sizeof(t_triangle));
	if (!nt)
		return (ft_free(inp->x) + ft_free(inp->y) + ft_free(inp->z) + 1);
	*dest = nt;
	(void)(masp2(&nt->a, inp->x, &nt->b, inp->y) && masp2(&nt->c, inp->z, &nt
			->ab, point_minus(inp->y, inp->x)) && masp2(&nt->bc, point_minus(inp
				->z, inp->y), &nt->ca, point_minus(inp->x, inp->z)));
	masp1(&nt->normal, 0);
	if (!nt->ab || !nt->bc || !nt->ca)
		return (1);
	m1 = point_minus_stack(inp->y, inp->x);
	m2 = point_minus_stack(inp->z, inp->x);
	nt->normal = point_cross(&m1, &m2);
	if (!nt->normal)
		return (1);
	normalize(nt->normal);
	nt->color = inp->col;
	nt->specular = inp->specular;
	nt->reflective = inp->reflective;
	return (0);
}

float	intersect_triangle(t_point *o, t_point *d, t_triangle *triangle)
{
	t_point		co;
	t_point		p;
	float		dt_t[2];
	int			c[3];

	dt_t[0] = dot(d, triangle->normal);
	if (dt_t[0] == 0)
		return (INF);
	co = point_minus_stack(triangle->a, o);
	dt_t[1] = dot(&co, triangle->normal) / dt_t[0];
	if (dt_t[1] < 0)
		return (INF);
	p = point_stack(o->x + d->x * dt_t[1], o->y + d->y * dt_t[1],
			o->z + d->z * dt_t[1]);
	c[0] = triple_product(triangle->normal, triangle->a, &p, triangle->ab) >= 0;
	c[1] = triple_product(triangle->normal, triangle->b, &p, triangle->bc) >= 0;
	c[2] = triple_product(triangle->normal, triangle->c, &p, triangle->ca) >= 0;
	if (c[0] == c[1] && c[1] == c[2])
		return (dt_t[1]);
	else
		return (INF);
}

float	closest_intersection_triangle(t_point *o, t_point *d, t_pair *t,
	t_object *closest_object)
{
	float		inter;
	int			i;

	i = 0;
	while (i < g_scene->triangles_num)
	{
		inter = intersect_triangle(o, d, g_scene->triangles[i]);
		if (inter >= t->t_min && inter <= t->t_max && inter < closest_object->t)
		{
			closest_object->t = inter;
			closest_object->id = 2;
			closest_object->obj = g_scene->triangles[i];
		}
		i++;
	}
	return (closest_object->t);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:35:34 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:37 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

void	put_pixel(t_data *img, int x, int y, unsigned int col)
{
	img->addr[(((unsigned)g_scene->res_y >> 1u) + y) *(img->line_length >> 2u)
		+ ((unsigned)g_scene->res_x >> 1u) + x] = col;
}

t_point	*reflect_ray(t_point *l, t_point *n)
{
	float	dt;

	dt = 2.f * dot(n, l);
	l->x = n->x * dt - l->x;
	l->y = n->y * dt - l->y;
	l->z = n->z * dt - l->z;
	return (l);
}

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	char	*new_ptr;
	char	*my_ptr;
	size_t	i;

	new_ptr = (char *) malloc (new_size);
	my_ptr = (char *)ptr;
	i = 0;
	while (i < size)
	{
		new_ptr[i] = my_ptr[i];
		i++;
	}
	return (new_ptr);
}

int	ft_array_size(char **arr)
{
	int		size;

	if (arr == NULL)
		return (-1);
	size = 0;
	while (*arr++)
		size++;
	return (size);
}

void	ft_normalize_vect(t_point *p, char *message)
{
	float		length;

	length = p->x * p->x + p->y * p->y + p->z * p->z;
	if (fabsf(length - 1) > 1e-3)
	{
		ft_putstr_fd(WARNING"Warning"RESET, 1);
		ft_putstr_fd(", ", 1);
		ft_putstr_fd(message, 1);
		ft_putstr_fd(" vector is not normalized, scaling its length to 1\n", 1);
		normalize(p);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:05:04 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	ft_check_rangef(float f, int mi, int ma, char *message)
{
	if (!(f < (float)mi || f > (float)ma))
		return (0);
	ft_putstr_fd(ERROR "ERROR\n" RESET, 1);
	ft_putstr_fd("Incorrect ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd(" value, it must be in range [", 1);
	ft_putnbr_fd(mi, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(ma, 1);
	ft_putstr_fd("]\n", 1);
	return (ft_exit_all(""));
}

int	ft_check_rangei(int i, int mi, int ma, char *message)
{
	if (!(i < mi || i > ma))
		return (0);
	ft_putstr_fd(ERROR "ERROR\n" RESET, 1);
	ft_putstr_fd("Incorrect ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd(" value (", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("), it must be in range [", 1);
	ft_putnbr_fd(mi, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(ma, 1);
	ft_putstr_fd("]\n", 1);
	return (ft_exit_all(""));
}

void	ft_line_free(char **line)
{
	char	**ptr;

	ptr = line;
	if (!line)
		return ;
	while (*line)
		free(*line++);
	free(ptr);
}

int	ft_append_array(void ***array_ptr, size_t wc, size_t size)
{
	void	*new_array;

	new_array = malloc(size * (wc + 1));
	if (!new_array)
		return (1);
	ft_memcpy(new_array, *array_ptr, size * wc);
	ft_bzero((char *)new_array + wc * size, size);
	free(*array_ptr);
	*array_ptr = new_array;
	return (0);
}

int	ft_iscomma(int __c)
{
	return (__c == ',');
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:44:28 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:35:45 by tlucanti         ###   ########.fr       */
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
