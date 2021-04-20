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
