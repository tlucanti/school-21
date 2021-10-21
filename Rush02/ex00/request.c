/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:37:18 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:37:19 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_outl *g_out_list;
t_list *g_table;

int		request(char *str)
{
	int len;

	len = str_len(str);
	if (!find_number(g_table, str, len))
		return (0);
	else
		return (1);
}

int		find_number(t_list *table, char *str, int len)
{
	while (table)
	{
		if (len == table->size)
		{
			if (!str_cmp(table->number, str))
			{
				push_out_list(&g_out_list, table->digit_name);
				return (0);
			}
		}
		table = table->next;
	}
	return (1);
}

int		str_cmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}
