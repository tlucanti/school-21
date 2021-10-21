/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:52:18 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/19 12:52:20 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_iter_num;

void	print_state(int *state)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = (char)(state[i] + 48);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	g_iter_num++;
}

int		check_state(int *state, int val, int req_depth)
{
	int i;

	i = 0;
	while (i < req_depth)
	{
		if (state[i] == val || i - state[i] == req_depth - val
			|| i + state[i] == req_depth + val)
			return (0);
		i++;
	}
	return (1);
}

void	deeep_check(int *state, int req_depth)
{
	int i;

	i = 0;
	while (i < 10)
	{
		state[req_depth] = i;
		if (check_state(state, i, req_depth))
		{
			if (req_depth == 9)
				print_state(state);
			else
			{
				deeep_check(state, req_depth + 1);
			}
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int state[10];

	g_iter_num = 0;
	deeep_check(state, 0);
	return (g_iter_num);
}
