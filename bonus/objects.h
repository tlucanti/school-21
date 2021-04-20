/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:36:34 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/18 14:36:34 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_pair
{
	float	t_min;
	float	t_max;
}			t_pair;

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}			t_color;

typedef struct s_matrix3
{
	float	a11;
	float	a12;
	float	a13;
	float	a21;
	float	a22;
	float	a23;
	float	a31;
	float	a32;
	float	a33;
}			t_matrix3;

typedef struct s_light
{
	char		type;
	t_color		*color;
	t_point		*vect;
}				t_light;

typedef struct s_sphere
{
	t_point			*center;
	unsigned int	color;
	int				specular;
	float			reflective;
	float			radius_sq;
}					t_sphere;

typedef struct s_plane
{
	t_point			*point;
	t_point			*normal;
	unsigned int	color;
	int				specular;
	float			reflective;
}					t_plane;

typedef struct s_triangle
{
	t_point			*normal;
	t_point			*a;
	t_point			*c;
	t_point			*ab;
	t_point			*bc;
	t_point			*ca;
	t_point			*b;
	unsigned int	color;
	int				specular;
	float			reflective;
}					t_triangle;

typedef struct s_square
{
	t_point			*center;
	t_point			*normal;
	t_point			*v1;
	t_point			*v2;
	float			d;
	unsigned int	color;
	int				specular;
	float			reflective;
}					t_square;

typedef struct s_cylinder
{
	t_point			*center;
	t_point			*q;
	float			r_sq;
	float			h_half;
	unsigned int	color;
	int				specular;
	float			reflective;
}					t_cylinder;

typedef struct s_circle
{
	t_point			*center;
	t_point			*normal;
	float			r_sq;
	unsigned int	color;
	int				specular;
	float			reflective;
}					t_circle;

typedef struct s_camera
{
	float		fovx;
	float		fovy;
	float		alpha;
	float		theta;
	float		gamma;
	t_point		*o;
	t_point		*view_vector;
	t_matrix3	*rotation_matrix;
}				t_camera;

typedef struct s_light_input
{
	char		type;
	float		intensity;
	t_color		*rgb;
	t_point		*vect;
}				t_light_input;

typedef struct s_sphere_input
{
	t_point			*center;
	float			radius;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_sphere_input;

typedef struct s_plane_input
{
	t_point			*p;
	t_point			*normal;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_plane_input;

typedef struct s_square_input
{
	t_point			*center;
	t_point			*normal;
	float			d;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_square_input;

typedef struct s_cylinder_input
{
	t_point			*center;
	t_point			*vec;
	float			d;
	float			h;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_cylinder_input;

typedef struct s_triangle_input
{
	t_point			*x;
	t_point			*y;
	t_point			*z;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_triangle_input;

typedef struct s_circle_input
{
	t_point			*center;
	t_point			*normal;
	float			radius;
	unsigned int	col;
	int				specular;
	float			reflective;
}					t_circle_input;

typedef struct s_camera_input
{
	float		fovx;
	float		fovy;
	t_point		*o;
	t_point		*view_vector;
}				t_camera_input;

#endif
