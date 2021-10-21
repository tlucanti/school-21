/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:59:52 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/23 20:59:54 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_2_horizontal(int n, int l);

int	check_2_vertical(int *r, int i, int l);

int	check_3_horizontal(int num, int l);

int	check_3_vertical(int *r, int i, int l);

int	gorizontal(int *map, int *g_state)
{
	int i;

	i = -1;
	while (++i < 4)
		if ((g_state[i + 12] == 1 && !(map[i] / 1000 == 4)) ||
			(g_state[i + 12] == 2 && !check_2_horizontal(map[i], 1)) ||
			(g_state[i + 12] == 3 && !check_3_horizontal(map[i], 1)) ||
			(g_state[i + 12] == 4 && !((map[i] == 1234))))
			return (0);
	i = -1;
	while (++i < 4)
		if ((g_state[i + 8] == 1 && !((map[i] % 10 == 4))) ||
			(g_state[i + 8] == 2 && !check_2_horizontal(map[i], 0)) ||
			(g_state[i + 8] == 3 && !check_3_horizontal(map[i], 0)) ||
			(g_state[i + 8] == 4 && !((map[i] == 4321))))
			return (0);
	printf("g\n");
	return (1);
}

int	index_(int num, int index_)
{
	if (index_ == 0)
		return (num / 1000);
	if (index_ == 1)
		return ((num / 100) % 10);
	if (index_ == 2)
		return ((num / 10) % 10);
	else
		return (num % 10);
}

int	vertical(int *map, int *g_state)
{
	int i;

	i = -1;
	while (++i < 4)
		if ((g_state[i] == 1 && index_(map[0], i) != 4) ||
			(g_state[i] == 2 && !check_2_vertical(map, i, 1)) ||
			(g_state[i] == 3 && !check_3_vertical(map, i, 1)) ||
			(g_state[i] == 4 &&
			!(index_(map[0], i) < index_(map[1], i) <
			index_(map[2], i) < index_(map[3], i))))
			return (0);
	i = -1;
	while (++i < 4)
		if ((g_state[i + 4] == 1 && index_(map[3], i) != 4) ||
			(g_state[i + 4] == 2 && !check_2_vertical(map, i, 0)) ||
			(g_state[i + 4] == 3 && !check_3_vertical(map, i, 0)) ||
			(g_state[i + 4] == 4 &&
				!(index_(map[3], i) > index_(map[2], i) >
				index_(map[1], i) > index_(map[0], i))))
			return (0);
	printf("v\n");
	return (1);
}

int	check_map(int *map, int *g_state)
{
	if (vertical(map, g_state) && gorizontal(map, g_state))
		return (0);
	else
		return (1);
}
