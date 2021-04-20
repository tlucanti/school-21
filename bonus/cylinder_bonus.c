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
