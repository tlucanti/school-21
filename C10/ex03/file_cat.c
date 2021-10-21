/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:41:09 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 18:41:10 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

t_str	reallol(t_str str, char *str_append, int size)
{
	char	*new_str;
	char	*new_str_esp;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (str.size + size + 1));
	if (errno)
	{
		str.str = 0;
		str.size = 0;
		return (str);
	}
	new_str_esp = new_str;
	i = -1;
	while (++i < str.size)
		*new_str++ = *(str.str)++;
	i = -1;
	while (++i < size)
		*new_str++ = *str_append++;
	*new_str = 0;
	str.str = new_str_esp;
	str.size += size;
	return (str);
}

t_str	read_file(char *path)
{
	int		f_desc;
	char	buffer[BUFF_SIZE];
	int		read_bytes;
	t_str	file;

	f_desc = open(path, O_RDONLY);
	file.str = (char *)malloc(sizeof(char));
	file.size = 0;
	file.str[0] = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(f_desc, buffer, BUFF_SIZE);
		file = reallol(file, buffer, read_bytes);
		if (errno)
		{
			err(errno, path);
			return (file);
		}
	}
	close(f_desc);
	return (file);
}

t_str	file_cat(char **argv)
{
	t_str	file;
	t_str	new_file;
	int		any_files;

	file.str = (char *)malloc(sizeof(char));
	file.str[0] = 0;
	file.size = 0;
	any_files = 0;
	argv--;
	while (*(++argv))
	{
		new_file = read_file(*argv);
		if (!new_file.str)
			continue ;
		file = reallol(file, new_file.str, new_file.size);
		any_files++;
	}
	if (any_files)
		return (file);
	else
	{
		file.str = 0;
		return (file);
	}
}

int		str_n_copy_buff(char *dest, t_str str, int str_i, int n)
{
	int written_bytes;

	written_bytes = 0;
	while (str_i + written_bytes < str.size && written_bytes < n)
	{
		*dest++ = str.str[str_i + written_bytes];
		written_bytes++;
	}
	return (written_bytes);
}
