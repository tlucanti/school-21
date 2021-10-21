/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:27:04 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:27:06 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <stdio.h>

#define BUFF_SIZE 256

void	print_str(char *str, int new_line);

void	print_err(char *str, int new_line)
{
	while (*str)
		write(2, str++, 1);
	if (new_line)
		write(2, "\n", 1);
}

void	err(int errcode, char *path)
{
	print_err("ft_cat: ", 0);
	print_err(path, 0);
	print_err(": ", 0);
	print_err(strerror(errcode), 1);
}

int		str_cmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		print_stdin(void)
{
	int		f_desc;
	char	buffer[BUFF_SIZE];
	int		read_bytes;

	while (1)
	{
		f_desc = 0;
		while ((read_bytes = read(f_desc, buffer, BUFF_SIZE)) > 0)
			write(1, buffer, read_bytes);
		close(f_desc);
		if (errno)
			return (0);
	}
}

int		print_file(int argc, char **argv)
{
	int		f_desc;
	char	buffer[BUFF_SIZE];
	int		read_bytes;

	if (argc == 1)
		return (print_stdin());
	while (*(++argv))
	{
		if (str_cmp(*argv, "-") == 0)
		{
			errno = print_stdin();
			continue ;
		}
		f_desc = open(*argv, O_RDONLY);
		if (errno)
		{
			err(errno, *argv);
			errno = 0;
			continue ;
		}
		while ((read_bytes = read(f_desc, buffer, BUFF_SIZE)) > 0)
			write(1, buffer, read_bytes);
		close(f_desc);
	}
	return (0);
}
