/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:34:58 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:35:00 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	print_str(char *str, int new_line)
{
	if (!str)
		return ;
	if (!*str)
		return ;
	while (*str)
		write(1, str++, 1);
	if (new_line)
		write(1, "\n", 1);
}

t_str	tail(t_str str, int i)
{
	if (!str.str)
	{
		return (str);
	}
	if (i > str.size)
		return (str);
	str.str += str.size - i;
	str.size = i;
	return (str);
}

void	many_files(char **argv, int bytes)
{
	t_str	text;
	int		not_first_file;

	not_first_file = 0;
	while (*argv)
	{
		text = tail(read_file(*argv), bytes);
		if (!text.str)
		{
			argv++;
			continue ;
		}
		if (*(argv) && not_first_file++)
		{
			write(1, "\n", 1);
			write(1, "==> ", 4);
			print_str(*argv, 0);
			write(1, " <==\n", 5);
			print_t_str(text, 0);
			argv++;
		}
	}
}

int		main(int argc, char **argv)
{
	int		bytes;

	if (argc < 3)
		return (0);
	bytes = str2int(*(argv + 2));
	argv += 3;
	if (argc == 3)
		print_t_str(tail(read_stdin(), bytes), 0);
	else if (argc == 4)
		print_t_str(tail(read_file(*argv), bytes), 0);
	else
		many_files(argv, bytes);
	return (0);
}
