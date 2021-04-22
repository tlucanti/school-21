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
