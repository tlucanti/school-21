/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:59:43 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/23 20:59:46 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *g_state;
int *g_int_map;
int g_i;
int *g_vars;

int		check_map(int *map, int *g_state);

void	print_state(int *map);

void	print_str(char *str);

int		index_(int num, int index_);

int		*init_vars(int *vars);

int		*init_vars1(int *a);

int		*init_vars2(int *a);

int		vert(void)
{
	int n1;
	int n2;
	int n3;
	int n4;

	g_i = -1;
	while (++g_i < 4)
	{
		n1 = index_(g_int_map[0], g_i);
		n2 = index_(g_int_map[1], g_i);
		n3 = index_(g_int_map[2], g_i);
		n4 = index_(g_int_map[3], g_i);
		if (n1 == n2 || n1 == n3 || n1 == n4 ||
			n2 == n3 || n2 == n4 || n3 == n4)
			return (0);
	}
	return (1);
}

int		next(int ii, int f)
{
	if (f == 0)
		return (0);
	g_i = -1;
	while (g_int_map[ii] != g_vars[++g_i])
	{
	}
	if (g_i == 24)
	{
		g_int_map[ii] = 0;
		return (0);
	}
	g_int_map[ii] = g_vars[g_i + 1];
	return (1);
}

int		sudoku(void)
{
	int f;

	f = 1;
	while (next(0, f))
	{
		while (next(1, f))
		{
			while (next(2, f))
			{
				while (next(3, f))
				{
					if (!vert())
						continue ;
					f = check_map(g_int_map, g_state);
				}
			}
		}
	}
	if (f == 0)
		return (1);
	return (0);
}

int		*parse_input(char *str)
{
	g_state = (int *)malloc(sizeof(int) * 16);
	if (!g_state)
		return (0);
	g_i = -1;
	while (++g_i < 16)
	{
		if (g_i % 2 == 0 && (str[g_i] < 48 || str[g_i] > 57))
			return (0);
		if (g_i % 2 != 0 && str[g_i] != 32)
			return (0);
		g_state[g_i] = str[g_i] - 48;
	}
	if (!str[g_i])
		return (0);
	return (g_state);
}

int		main(int argc, char **argv)
{
	g_int_map = (int *)malloc(sizeof(int) * 4);
	g_int_map[0] = 0;
	g_int_map[1] = 0;
	g_int_map[2] = 0;
	g_int_map[3] = 0;
	g_vars = (int *)malloc(sizeof(int) * 25);
	g_vars = init_vars1(g_vars);
	g_vars = init_vars2(g_vars);
	if (argc != 2 || parse_input(*(argv + 1)) == 0)
		print_str("Error\n");
	else if (sudoku())
	{
		print_state(g_int_map);
	}
	else
		print_str("Error\n");
	return (0);
}
