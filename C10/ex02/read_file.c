/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:36:52 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:36:53 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

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
	str.size += size;
	str.str = new_str_esp;
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

void	print_t_str(t_str fl, int new_line)
{
	int i;

	i = 0;
	while (i < fl.size)
	{
		write(1, fl.str + i, 1);
		i++;
	}
	if (new_line)
		write(1, "\n", 1);
}

t_str	read_stdin(void)
{
	char	buffer[BUFF_SIZE];
	int		read_bytes;
	t_str	stream;

	stream.str = (char *)malloc(sizeof(char));
	stream.size = 0;
	while (1)
	{
		while ((read_bytes = read(0, buffer, BUFF_SIZE)) > 0)
		{
			buffer[read_bytes] = 0;
			stream = reallol(stream, buffer, read_bytes);
			if (!stream.str)
			{
				stream.str = 0;
				stream.size = 0;
				return (stream);
			}
			stream.size += read_bytes;
		}
		close(0);
		if (errno)
			return (stream);
	}
}
