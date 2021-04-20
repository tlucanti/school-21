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
