/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:23:58 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/22 19:24:07 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					str_len(char *str)
{
	int n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

char				*str_cpy_smart(char *dest, char *src)
{
	char *dest_esp;

	dest_esp = dest;
	if (dest == 0 || src == 0)
		return (0);
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (dest_esp);
}

char				*str_dup(char *src)
{
	return (str_cpy_smart((char *)malloc(sizeof(char) *
		str_len(src) + 1), src));
}

int					init_str(t_stock_str *el, char *str)
{
	el->size = str_len(str);
	el->str = str;
	el->copy = str_dup(str);
	if (el->copy == 0)
		return (0);
	else
		return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *arr;
	t_stock_str *arr_esp;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == 0)
		return (0);
	arr_esp = arr;
	while (*av)
	{
		if (!init_str(arr++, *(av++)))
			return (0);
	}
	arr->str = 0;
	arr->copy = 0;
	arr->size = 0;
	return (arr_esp);
}
