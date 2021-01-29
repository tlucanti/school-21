/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:46:14 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:46:16 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *buff, ...)
{
	long long			printed_syms;
	t_format_qualifiers	format_qualifiers;
	va_list				args;

	if (buff == NULL)
		return (-1);
	printed_syms = 0;
	va_start(args, buff);
	while (*buff)
	{
		printed_syms++;
		if (*buff != '%')
			write(1, buff, 1);
		else
		{
			buff++;
			printed_syms += ft_format_parcer(
				&buff, *&format_qualifiers, args, printed_syms) - 1;
		}
		buff++;
	}
	va_end(args);
	return ((int)printed_syms);
}
