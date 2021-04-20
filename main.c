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
	if (init_scene())
		return (0);
	g_scene->dist = 1.f + EPS;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("cannot open ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" file\n", 1);
		return (1);
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
