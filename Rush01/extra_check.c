/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:59:59 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/23 21:00:02 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_a1;
int g_a2;
int g_a3;
int g_a4;
int g_a;

int	index_(int num, int index_);

int	check_2_horizontal(int n, int l)
{
	if (l)
	{
		if (n == 3124 || n == 3214 ||
			n == 3142 || n == 3241 ||
			(n / 100) % 10 == 4)
			return (1);
		else
			return (0);
	}
	else
	{
		if (n == 4213 || n == 4123 ||
			n == 2431 || n == 1423 ||
			(n / 10) % 10 == 4)
			return (1);
		else
			return (0);
	}
}

int	check_2_vertical(int *r, int i, int l)
{
	g_a1 = index_(r[0], i);
	g_a2 = index_(r[1], i);
	g_a3 = index_(r[2], i);
	g_a4 = index_(r[3], i);
	g_a = g_a1 * 1000 + g_a2 * 100 + g_a3 * 10 + g_a4;
	return (check_2_horizontal(g_a, l));
}

int	check_3_horizontal(int n, int l)
{
	if (l)
	{
		if (n == 1243 || n == 1324 ||
			n == 1342 || n == 2143 ||
			n == 2314 || n == 2341)
			return (1);
		else
			return (0);
	}
	else
	{
		if (n == 3421 || n == 4231 ||
			n == 2431 || n == 3412 ||
			n == 4132 || n == 1432)
			return (1);
		else
			return (0);
	}
}

int	check_3_vertical(int *r, int i, int l)
{
	g_a1 = index_(r[0], i);
	g_a2 = index_(r[1], i);
	g_a3 = index_(r[2], i);
	g_a4 = index_(r[3], i);
	g_a = g_a1 * 1000 + g_a2 * 100 + g_a3 * 10 + g_a4;
	return (check_3_horizontal(g_a, l));
}
