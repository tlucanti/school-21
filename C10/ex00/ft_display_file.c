/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:14:28 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:14:30 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 256

int		err(char *msg, int s)
{
	write(1, msg, s);
	return (0);
}

int		main(int argc, char **argv)
{
	int		f_desc;
	char	buffer[BUFF_SIZE];
	int		read_bytes;

	if (argc == 1)
		return (err("File name missing.\n", 19));
	if (argc > 2)
		return (err("Too many arguments.\n", 20));
	f_desc = open(argv[1], O_RDONLY);
	if (f_desc == -1)
		return (err("Cannot read file.\n", 18));
	while ((read_bytes = read(f_desc, buffer, BUFF_SIZE)) > 0)
		write(1, buffer, read_bytes);
	if (read_bytes == -1)
		return (err("Cannot read file.\n", 18));
	close(f_desc);
	return (0);
}
