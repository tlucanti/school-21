//
// Created by kostya on 3/23/21.
//

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
