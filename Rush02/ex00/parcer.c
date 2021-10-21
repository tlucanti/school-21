/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:36:40 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:36:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	g_write_buff[BUFF_SIZE] = {0};
char	g_char_buff;

int		parcer(char *path)
{
	int		f_desc;
	char	*digit_name;
	char	*number;

	g_char_buff = 0;
	f_desc = open(path, O_RDONLY);
	while (1)
	{
		if (!read(f_desc, &g_char_buff, 1))
			return (0);
		if (g_char_buff == '\n')
			continue ;
		if (!(number = read_word(f_desc, 48, 57)))
			return (1);
		if (!(skip_spaces(f_desc)))
			return (1);
		if (!(digit_name = read_word(f_desc, 32, 126)))
			return (1);
		if (g_char_buff != '\n')
			return (1);
		if (!gen_push(number, digit_name))
			return (1);
	}
}

char	*read_word(int f_desc, int lb, int rb)
{
	int		write_counter;
	char	*str;

	write_counter = 0;
	str = (char *)malloc(sizeof(char));
	*str = 0;
	while (1)
	{
		if (g_char_buff >= lb && g_char_buff <= rb)
		{
			g_write_buff[write_counter] = g_char_buff;
			g_write_buff[++write_counter] = 0;
			if (write_counter == BUFF_SIZE - 1)
			{
				str = reallol(str, g_write_buff, BUFF_SIZE);
				if (!str)
					return (0);
				write_counter = 0;
			}
		}
		else
			return (reallol(str, g_write_buff, write_counter));
		if (!read(f_desc, &g_char_buff, 1))
			return (0);
	}
}

int		skip_spaces(int f_desc)
{
	while (g_char_buff == ' ')
		read(f_desc, &g_char_buff, 1);
	if (g_char_buff != ':')
		return (0);
	read(f_desc, &g_char_buff, 1);
	while (g_char_buff == ' ')
		read(f_desc, &g_char_buff, 1);
	return (1);
}
