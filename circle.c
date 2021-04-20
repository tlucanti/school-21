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
