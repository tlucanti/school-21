/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:53:13 by droslyn           #+#    #+#             */
/*   Updated: 2020/08/30 20:06:12 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_units(char *str, int len)
{
	char ch[2];

	ch[0] = *str;
	ch[1] = '\0';
	if (request(ch))
		return (ft_print_error());
	if (len > 3)
	{
		if (ft_million(len))
			return (1);
	}
	return (0);
}

int		ft_decimals(char *str, int len)
{
	char ch[3];

	ch[0] = str[0];
	ch[2] = '\0';
	if (*str == '1')
	{
		ch[1] = str[1];
		if (request(ch))
			return (ft_print_error());
		if (len - 1 > 3)
		{
			if (ft_million(len - 1))
				return (1);
		}
	}
	else
	{
		ch[1] = '0';
		if (request(ch))
			return (ft_print_error());
		if (*(str + 1) == '0')
			return (0);
		ft_units(str + 1, len - 1);
	}
	return (0);
}

int		ft_hundred(char *str)
{
	char	ch[2];

	ch[0] = *str;
	ch[1] = '\0';
	if (request(ch))
		return (ft_print_error());
	if (request("100"))
		return (ft_print_error());
	return (0);
}
