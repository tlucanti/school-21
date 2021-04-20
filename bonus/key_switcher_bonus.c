/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switcher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:57:28 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/17 19:57:56 by tlucanti         ###   ########.fr       */
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
