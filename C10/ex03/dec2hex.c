/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec2hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:48:58 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:48:59 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

char	*dec_to_base(long nbr, char *base, int *digits)
{
	int		num[33];
	char	*base_num;
	int		i;
	int		g_to_base;

	g_to_base = 16;
	i = 0;
	if (nbr == 0)
		return ("0\0");
	while (nbr)
	{
		num[i++] = nbr % g_to_base;
		nbr /= g_to_base;
	}
	*digits = i;
	base_num = (char *)malloc(sizeof(char) * (*digits + 1));
	if (!base_num)
		return (0);
	i = -1;
	while (++i < (*digits))
		base_num[i] = base[num[*digits - i - 1]];
	return (base_num);
}

char	*dec2hex(int num)
{
	int		digits;
	char	*ans;
	char	*hexnum;
	int		i;

	i = 0;
	digits = 1;
	ans = (char *)malloc(sizeof(char) * 8);
	if (!ans)
		return (0);
	hexnum = dec_to_base(num, "0123456789abcdef", &digits);
	if (!hexnum)
		return (0);
	while (i < 7 - digits)
		ans[i++] = 48;
	while (*hexnum)
		ans[i++] = *hexnum++;
	ans[7] = 0;
	return (ans);
}
