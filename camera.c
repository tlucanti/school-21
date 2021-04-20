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
	new_camera->alpha = tern_f(fabsf(inp->view_vector->z + inp->view_vector->x)
			< EPS, 0, -atanf(-inp->view_vector->x / inp->view_vector->z)
			+ tern_f(inp->view_vector->z < 0, PI, 0));
	new_camera->theta = tern_f(inp->view_vector->z + inp->view_vector->x < EPS,
			-significandf(inp->view_vector->y) * PI / 2, -atanf(inp->view_vector
				->y / sqrtf(inp->view_vector->x * inp->view_vector->x + inp
					->view_vector->z * inp->view_vector->z)));
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
