/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloatnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:51:47 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 18:51:51 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

u_int64_t	ft_float_invalid(double d, t_format_qualifiers fq)
{
	uint64_t	printed;
	u_int8_t	sgn;

	printed = 0;
	sgn = d < 0 ? 1 : 0;
	if (IS_INF(d))
	{
		fq.s = (char)(fq.s == '+' ? '+' * !sgn + '-' * sgn : fq.s);
		fq.w -= (fq.s != 0 && !sgn) + (fq.q == 0 && fq.o);
		printed += ft_pns((char *)" ", (fq.w - 3 - sgn) * (fq.a == 0));
		printed += write(1, sgn ? (char *)"-" : &fq.s, sgn || fq.s);
		printed += write(1, "inf", 3);
		printed += ft_pns((char *)" ", (fq.w - 3 - sgn) * (fq.a != 0));
	}
	else if (IS_NAN(d))
	{
		printed += write(1, "nan", 3 * fq.a);
		printed += ft_pns(" ", fq.w - 3);
		printed += write(1, "nan", 3 * !fq.a);
	}
	return (printed);
}

long long	ft_putfloatnbr_switcher(double d, t_format_qualifiers fq,
	u_int8_t form)
{
	int16_t		exp10;
	u_int64_t	printed;

	fq.q = fq.q == -1 ? 6 : fq.q;
	printed = ft_float_invalid(d, fq);
	exp10 = ft_log10(d < 0 ? -d : d);
	if (VALID_DOUBLE(d) && form == 'f')
		printed += ft_putfloatnbrf(d, fq, exp10);
	else if (VALID_DOUBLE(d) && form == 'e')
		printed += ft_putfloatnbre(d, fq, exp10);
	else if (VALID_DOUBLE(d) && form == 'g')
		printed += ft_putfloatnbrg(d, fq, exp10);
	return (printed);
}
