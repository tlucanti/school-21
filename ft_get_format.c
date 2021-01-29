/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:44:12 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:44:14 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*ft_get_format(const char *buff,
	t_format_qualifiers *format_qualifiers, va_list args)
{
	format_qualifiers->a = 0;
	format_qualifiers->z = 32;
	format_qualifiers->w = 0;
	format_qualifiers->q = -1;
	format_qualifiers->s = 0;
	format_qualifiers->o = 0;
	buff = ft_get_format_loop(buff, format_qualifiers, args);
	format_qualifiers->a = (int)(format_qualifiers->w < 0 ?
		(format_qualifiers->w *= -1) * 0 + 1 : format_qualifiers->a);
	format_qualifiers->z =
		(char)(format_qualifiers->a ? 32 : format_qualifiers->z);
	return (buff);
}

const char		*ft_get_format_loop(const char *buff,
	t_format_qualifiers *format_qualifiers, va_list args)
{
	while (*buff && !ft_ispecifier(*buff))
	{
		format_qualifiers->a = *buff == '-' ? 1 : format_qualifiers->a;
		format_qualifiers->z =
			(char)(*buff == '0' ? 48 : format_qualifiers->z);
		format_qualifiers->s = (char)(*buff == ' ' &&
			format_qualifiers->s != '+' ? 32 : format_qualifiers->s);
		format_qualifiers->s =
			(char)(*buff == '+' ? '+' : format_qualifiers->s);
		format_qualifiers->o = (char)(*buff == '#' ? 1 : format_qualifiers->o);
		if (*buff > 48 && *buff <= 57)
			buff += ft_atol_set(buff, &format_qualifiers->w) - 1;
		else if (*buff == '*')
			format_qualifiers->w = va_arg(args, int);
		if (*buff == '.' && *(buff + 1) == '*')
			(format_qualifiers->q = va_arg(args, int) + (size_t)(buff++) * 0)
			< 0 ? format_qualifiers->q = -1 : 0;
		else if (*buff == '.')
			buff += ft_atol_set(buff + 1, &format_qualifiers->q);
		buff++;
	}
	return (buff);
}

long long		ft_atol_set(const char *str, long long *var)
{
	int		digit_num;

	digit_num = 0;
	*var = 0;
	while (FT_ISDIGIT(*str))
	{
		*var = *var * 10 + *str++ - 48;
		digit_num++;
	}
	return (digit_num);
}
