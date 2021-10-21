/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:11:21 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:11:22 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_from_base;
int g_to_base;

int			check_str(char *str, int *g_base)
{
	char hash[256];

	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (0);
		hash[(int)*str]++;
		if (hash[(int)*str] == 2)
		{
			*g_base = -1;
			return (0);
		}
		str++;
		(*g_base)++;
	}
	if (*g_base <= 1)
		return (0);
	return (1);
}

long		power(int n, int p)
{
	int s;

	s = 1;
	while (p--)
		s *= n;
	return (s);
}

int			index_b(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str++ == c)
			return (i);
		i++;
	}
	return (-1);
}

long long	base_to_dec(char *nbr, char *base)
{
	long	dec_nbr;
	int		i;
	int		digits;

	g_from_base = 0;
	dec_nbr = 0;
	digits = 0;
	i = -1;
	check_str(base, &g_from_base);
	while (nbr[++i])
		digits++;
	i = -1;
	while (++i < digits)
		dec_nbr += power(g_from_base, digits - i - 1) * index_b(base, *nbr++);
	return (dec_nbr);
}

char		*dec_to_base(long nbr, char *base, int g_sign)
{
	int		num[33];
	int		digits;
	char	*base_num;
	int		i;

	g_to_base = 0;
	digits = 0;
	i = 0;
	check_str(base, &g_to_base);
	while (nbr)
	{
		if (++digits == 1 && nbr % g_to_base == 0)
			digits--;
		num[i++] = nbr % g_to_base;
		nbr /= g_to_base;
	}
	base_num = (char *)malloc(sizeof(char) * digits + (int)(g_sign == -1));
	i = -1;
	if (g_sign == -1)
		g_sign = 2;
	while (++i < digits)
		base_num[i + g_sign - 1] = base[num[digits - i - 1]];
	return (base_num);
}
