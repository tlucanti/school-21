/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:11:12 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:11:13 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_sign;

long long	base_to_dec(char *nbr, char *base);

char		*dec_to_base(long nbr, char *base, int g_sign);

int			index_b(char *str, char c);

int			check_str(char *str, int *g_base);

char		*start(char *str, int *sign)
{
	while ((*str == ' ' || *str == '\t' || *str == '\b'
		|| *str == '\r' || *str == '\n' || *str == '\v') && *str)
		str++;
	while (*str)
	{
		if (*str == '-')
			*sign *= -1;
		else if (*str == '+')
			*sign *= 1;
		else
			break ;
		str++;
	}
	return (str);
}

char		*ft_atoi_b_start(char *str)
{
	while ((*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r') && *str)
		str++;
	while (*str)
	{
		if (*str == '-')
			g_sign *= -1;
		if (*str != '+' && *str != '-')
			break ;
		str++;
	}
	return (str);
}

char		*ft_atoi_b(char *str, char *base)
{
	char *num_esp;

	g_sign = 1;
	str = ft_atoi_b_start(str);
	num_esp = str;
	while (*str)
	{
		if (index_b(base, *str) == -1)
			break ;
		str++;
	}
	*str = '\0';
	return (num_esp);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*from_base_num;
	long long	dec_num;
	char		*to_base_num;
	int			i;

	i = 0;
	if (!check_str(base_to, &i) || !check_str(base_from, &i))
		return (0);
	from_base_num = ft_atoi_b(nbr, base_from);
	if (from_base_num[0] == 0)
		return (0);
	if (from_base_num[0] == base_from[0])
	{
		to_base_num = (char *)malloc(sizeof(char));
		to_base_num[0] = base_to[0];
		return (to_base_num);
	}
	dec_num = base_to_dec(from_base_num, base_from);
	to_base_num = dec_to_base(dec_num, base_to, g_sign);
	if (to_base_num == 0)
		return (0);
	if (g_sign == -1)
		to_base_num[0] = '-';
	return (to_base_num);
}
