/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloatnbr_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:01:06 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 19:01:07 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putformat_f(u_int8_t sgn, t_format_qualifiers fq,
	int16_t exp10, uint64_t lll)
{
	uint64_t	printed;

	printed = 0;
	fq.s = (char)(fq.s == '+' ? '+' * !sgn + '-' * sgn : fq.s);
	fq.w -= (fq.s != 0 && !sgn) + (fq.q == 0 && fq.o);
	printed += write(1, sgn ? (char *)"-" : &fq.s, (sgn || fq.s != 0) &&
		fq.z == 48);
	if (fq.a == 0)
		printed += ft_pns(&fq.z, fq.w - FT_ABSNULL(exp10) - (exp10 <= 0) -
			fq.q - (fq.q != 0) - sgn);
	printed += write(1, sgn ? (char *)"-" : &fq.s, (sgn || fq.s != 0) &&
		fq.z == 32);
	printed += ft_putll(lll / 10, exp10, fq.q, 0);
	printed += write(1, ".", fq.q == 0 && fq.o);
	if (fq.a == 1)
		printed += ft_pns(&fq.z, fq.w - FT_ABSNULL(exp10) - (exp10 <= 0) -
			fq.q - (fq.q != 0) - sgn);
	return (printed);
}

long long	ft_putfloatnbrf(double d, t_format_qualifiers fq, int16_t exp10)
{
	u_int64_t	ll;
	uint64_t	lll;
	u_int8_t	sgn;

	sgn = d < 0 || IS_MNULL(d);
	d = FT_ABS(d);
	if (17 - exp10 > 308)
		d = d * ft_dpow(10, (17 - exp10) / 2) * ft_dpow(10, (17 - exp10) / 2 +
			(17 - exp10) % 2);
	else
		d = d * ft_dpow(10, 17 - exp10);
	if (d < ft_dpow(10, 16))
		d += 9;
	ll = (u_int64_t)d;
	lll = ft_oddceil(ll, fq.q, exp10);
	if (ft_log10ull(lll) > ft_log10ull(ll))
	{
		lll /= 10;
		exp10++;
	}
	return (ft_putformat_f(sgn, fq, exp10, lll));
}
