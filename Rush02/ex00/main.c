/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:36:21 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:36:23 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_list	*g_table;
t_list	*g_complex;
t_outl	*g_out_list;

int		main(int argc, char **argv)
{
	char	*number;

	g_table = 0;
	g_complex = 0;
	g_out_list = 0;
	if (argc == 1)
		return (0);
	if (argc > 4)
		return (0);
	number = argv[argc - 1];
	if (parcer(argc == 2 ? DICT_PATH : argv[1]))
		write(2, "Dict Error\n", 11);
	if (!ft_check_num(number))
		final_print(g_out_list);
	clear_t_list(g_table);
	return (0);
}

void	final_print(t_outl *list)
{
	while (list)
	{
		if (list != g_out_list)
			write(1, " ", 1);
		print_str(list->data);
		list = list->next;
	}
	write(1, "\n", 1);
}

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}
