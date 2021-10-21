/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:15:49 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:15:50 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <stdio.h>

int		print_file(int argc, char **argv, int *currentfile);

void	err(int errcode, char *path);

void	print_str(char *str, int new_line)
{
	while (*str)
		write(1, str++, 1);
	if (new_line)
		write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int currentfile;

	currentfile = 0;
	errno = print_file(argc, argv, &currentfile);
	if (errno)
		err(errno, argv[currentfile]);
	return (0);
}
