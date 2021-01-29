/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:45:28 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 12:54:15 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_pns(char *s, long long count)
{
	long long ret;

	ret = count;
	if (count <= 0)
		return (0);
	while (count--)
		write(1, s, 1);
	return (ret);
}

int			ft_ispecifier(char a)
{
	return ((a) == 'c' || (a) == 's' || (a) == 'p'
	|| (a) == 'd' || (a) == 'i' || (a) == 'u' || (a) == 'x' || (a) == 'X'
	|| (a) == '%' || (a) == 'n' || (a) == 'l' || (a) == 'h' || (a) == 'o'
	|| (a) == 'f' || (a) == 'g' || (a) == 'e');
}
