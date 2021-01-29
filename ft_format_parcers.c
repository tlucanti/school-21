/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parcers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:34:10 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:34:12 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_format_parcer(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms)
{
	if (*(*buff = ft_get_format(*buff, &format_qualifiers, args)) == 0)
		return (0 * (long long)(*buff)--);
	else if (**buff == '%')
		return (ft_putcharf('%', format_qualifiers));
	else if (**buff == 'c')
		return (ft_putcharf(va_arg(args, int), format_qualifiers));
	else if (**buff == 's')
		return (ft_putnstrf(va_arg(args, char *), format_qualifiers));
	else if (**buff == 'p')
		return (ft_putaddressf(va_arg(args, void *),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'd' || **buff == 'i')
		return (ft_putnmbrf(va_arg(args, int), format_qualifiers, 1));
	else if (**buff == 'u')
		return (ft_putnmbrf((unsigned)va_arg(args, int), format_qualifiers, 0));
	else if (**buff == 'x')
		return (ft_puthexnbrf((unsigned)va_arg(args, int),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'X')
		return (ft_puthexnbrf((unsigned)va_arg(args, int),
			(char *)"0123456789ABCDEF0X", format_qualifiers));
	else if (**buff == 'n')
		return ((*va_arg(args, int *) = (int)printed_syms - 1) * 0);
	return (ft_format_parcerl(buff, format_qualifiers, args, printed_syms));
}

long long		ft_format_parcerl(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms)
{
	if (**buff == 'o')
		return (ft_putoctnbrf((unsigned)va_arg(args, int),
			(char *)"01234567", format_qualifiers));
	else if (**buff == 'l' && *(*buff + 1) == 'o' && (*buff += 1))
		return (ft_putoctnbrf((unsigned long)va_arg(args, long),
			(char *)"01234567", format_qualifiers));
	else if (**buff == 'f' || **buff == 'g' || **buff == 'e')
		return (ft_putfloatnbr_switcher(va_arg(args, double),
		format_qualifiers, **buff));
	else if ((**buff == 'l' && (*(*buff + 1) == 'd' || *(*buff + 1) == 'i')))
	{
		*buff = *buff + 1;
		return (ft_putnmbrf(va_arg(args, long), format_qualifiers, 1));
	}
	else if (**buff == 'l' && *(*buff + 1) == 'u' && (*buff += 1))
		return (ft_putnmbrf(va_arg(args, long), format_qualifiers, 0));
	else if (**buff == 'l' && *(*buff + 1) == 'x' && (*buff += 1))
		return (ft_puthexnbrf(va_arg(args, long),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'l' && *(*buff + 1) == 'X' && (*buff += 1))
		return (ft_puthexnbrf(va_arg(args, long),
			(char *)"0123456789ABCDEF0X", format_qualifiers));
	else if (**buff == 'l' && *(*buff + 1) == 'n' && (*buff += 1))
		return ((*va_arg(args, long *) = (long)printed_syms - 1) * 0);
	return (ft_format_parcerll(buff, format_qualifiers, args, printed_syms));
}

long long		ft_format_parcerll(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms)
{
	if (**buff == 'h' && *(*buff + 1) == 'h' &&
		*(*buff + 2) == 'o' && *(*buff += 2))
		return (ft_putoctnbrf((unsigned char)va_arg(args, int),
			(char *)"01234567", format_qualifiers));
	else if ((**buff == 'l' && *(*buff + 1) == 'l') &&
		(*(*buff + 2) == 'd' || *(*buff + 2) == 'i'))
	{
		*buff = *buff + 2;
		return (ft_putnmbrf(va_arg(args, long long), format_qualifiers, 1));
	}
	else if (**buff == 'l' && *(*buff + 1) == 'l' &&
		*(*buff + 2) == 'u' && (*buff += 2))
		return (ft_putnmbrf(va_arg(args, long long), format_qualifiers, 0));
	else if (**buff == 'l' && *(*buff + 1) == 'l' &&
		*(*buff + 2) == 'x' && (*buff += 2))
		return (ft_puthexnbrf(va_arg(args, long long),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'l' && *(*buff + 1) == 'l' &&
		*(*buff + 2) == 'X' && (*buff += 2))
		return (ft_puthexnbrf(va_arg(args, long long),
			(char *)"0123456789ABCDEF0X", format_qualifiers));
	else if (**buff == 'l' && *(*buff + 1) == 'l' &&
		*(*buff + 2) == 'n' && (*buff += 2))
		return ((*va_arg(args, long long *) = printed_syms - 1) * 0);
	return (ft_format_parcerh(buff, format_qualifiers, args, printed_syms));
}

long long		ft_format_parcerh(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms)
{
	if (**buff == 'l' && *(*buff + 1) == 'l' && *(*buff + 2) == 'o'
		&& *(*buff += 2))
		return (ft_putoctnbrf(va_arg(args, long long),
			(char *)"01234567", format_qualifiers));
	else if (**buff == 'h' && *(*buff + 1) == 'o' && *(*buff += 1))
		return (ft_putoctnbrf((unsigned short)va_arg(args, int),
			(char *)"01234567", format_qualifiers));
	else if ((**buff == 'h' && (*(*buff + 1) == 'd' || *(*buff + 1) == 'i')))
	{
		*buff = *buff + 1;
		return (ft_putnmbrf((short)va_arg(args, int), format_qualifiers, 1));
	}
	else if (**buff == 'h' && *(*buff + 1) == 'u' && (*buff += 1))
		return (ft_putnmbrf((unsigned short)va_arg(args, int),
			format_qualifiers, 0));
	else if (**buff == 'h' && *(*buff + 1) == 'x' && (*buff += 1))
		return (ft_puthexnbrf((unsigned short)va_arg(args, int),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'h' && *(*buff + 1) == 'X' && (*buff += 1))
		return (ft_puthexnbrf((unsigned short)va_arg(args, int),
			(char *)"0123456789ABCDEF0X", format_qualifiers));
	else if (**buff == 'h' && *(*buff + 1) == 'n' && (*buff += 1))
		return ((*va_arg(args, short *) = (short)((printed_syms - 1) * 0)));
	return (ft_format_parcerhh(buff, format_qualifiers, args, printed_syms));
}

long long		ft_format_parcerhh(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms)
{
	if ((**buff == 'h' && *(*buff + 1) == 'h') &&
		(*(*buff + 2) == 'd' || *(*buff + 2) == 'i'))
	{
		*buff = *buff + 2;
		return (ft_putnmbrf((char)va_arg(args, int), format_qualifiers, 1));
	}
	else if (**buff == 'h' && *(*buff + 1) == 'h' &&
		*(*buff + 2) == 'u' && (*buff += 2))
		return (ft_putnmbrf((unsigned char)va_arg(args, int),
			format_qualifiers, 0));
	else if (**buff == 'h' && *(*buff + 1) == 'h' &&
		*(*buff + 2) == 'x' && (*buff += 2))
		return (ft_puthexnbrf((unsigned char)va_arg(args, int),
			(char *)"0123456789abcdef0x", format_qualifiers));
	else if (**buff == 'h' && *(*buff + 1) == 'h' &&
		*(*buff + 2) == 'X' && (*buff += 2))
		return (ft_puthexnbrf((unsigned char)va_arg(args, int),
			(char *)"0123456789ABCDEF0X", format_qualifiers));
	else if (**buff == 'h' && *(*buff + 1) == 'h' &&
		*(*buff + 2) == 'n' && (*buff += 2))
		return ((*va_arg(args, char *) = (char)((printed_syms - 1) * 0)));
	return (0);
}
