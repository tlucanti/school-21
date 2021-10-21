/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:02:35 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 21:02:36 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int g_address;

void	print_str(char *str, int newline)
{
	while (*str)
		write(1, str++, 1);
	if (newline)
		write(1, "\n", 1);
}

void	print_dump(t_str str)
{
	char	buffer[16];
	int		read_bytes;
	char	*hex_addres;
	int		str_i;
	int		i;

	str_i = 0;
	while (str_i < str.size)
	{
		i = 0;
		hex_addres = dec2hex(g_address);
		if (!(hex_addres))
			return ;
		print_str(hex_addres, 0);
		read_bytes = str_n_copy_buff(buffer, str, str_i, 16);
		g_address += read_bytes;
		while (i < read_bytes)
			put_np_char(buffer[i++]);
		write(1, "\n", 1);
		str_i += read_bytes;
	}
	hex_addres = dec2hex(g_address);
	if (!(hex_addres))
		return ;
	print_str(hex_addres, 1);
}

int		main(int argc, char **argv)
{
	t_str	str;

	g_address = 0;
	if (argc < 3)
		return (0);
	argv += 2;
	str = file_cat(argv);
	if (str.str)
	{
		if (str.size == 0)
			return (0);
		print_dump(str);
	}
	else
		err(EBADF, *argv);
}
