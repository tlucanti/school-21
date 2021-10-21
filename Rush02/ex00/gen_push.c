/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:36:15 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:36:17 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_list	*g_table;
t_list	*g_complex;

int		gen_push(char *number, char *digit_name)
{
	int digit;

	digit = str_len(number);
	if (digit > 2)
	{
		if (defaultsn(number))
			push(&g_table, number, digit_name, digit);
		else
			push(&g_complex, number, digit_name, digit);
	}
	else if (str_len(number) == 2)
	{
		if (defaults2(number))
			push(&g_table, number, digit_name, digit);
		else
			push(&g_complex, number, digit_name, digit);
	}
	else if (str_len(number) == 1)
		push(&g_table, number, digit_name, digit);
	else
		return (0);
	return (1);
}

int		defaults2(char *number)
{
	if (number[0] == '1')
		return (1);
	if (number[1] == '0')
		return (1);
	return (0);
}

int		defaultsn(char *number)
{
	if (number[0] != '1')
		return (0);
	while (*++number)
	{
		if (*number != '0')
			return (0);
	}
	return (1);
}
