/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloatnbr_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:52:15 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 18:52:49 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putformat_e(uint64_t lll, t_format_qualifiers fq,
	int16_t exp10, u_int8_t sign_ceiled)
{
	uint64_t	printed;
	u_int8_t	sgn;

	sgn = (sign_ceiled & 0x2u) >> 0x1u;
	printed = 0;
	fq.s = (char)(fq.s == '+' ? '+' * !sgn + '-' * sgn : fq.s);
	fq.w -= (fq.s != 0 && !sgn) + (fq.q == 0 && fq.o);
	printed += write(1, sgn ? (char *)"-" : &fq.s, (sgn || fq.s != 0) &&
		fq.z == 48);
	if (fq.a == 0)
		printed += ft_pns(&fq.z, fq.w - fq.q - 6 - (FT_ABS(exp10) >= 100) +
			(fq.q == 0) - sgn);
	printed += write(1, sgn ? (char *)"-" : &fq.s, (sgn || fq.s != 0) &&
		fq.z == 32);
	printed += ft_putll(lll / 10, 1, fq.q, sign_ceiled & 0x1u);
	printed += write(1, ".", fq.q == 0 && fq.o);
	printed += write(1, "e", 1);
	printed += write(1, exp10 >= 0 ? "+" : "-", 1);
	printed += ft_put3nbr(FT_ABS(exp10));
	if (fq.a == 1)
		printed += ft_pns(&fq.z, fq.w - fq.q - 6 - (FT_ABS(exp10) >= 100) -
			sgn + (fq.q == 0));
	return (printed);
}

long long	ft_putfloatnbre(double d, t_format_qualifiers fq, int16_t exp10)
{
	uint64_t	ll;
	uint64_t	lll;
	u_int8_t	sign_ceiled;

	sign_ceiled = 0;
	if (d < 0 || IS_MNULL(d))
		sign_ceiled |= 0x2u;
	d = FT_ABS(d);
	if (17 - exp10 > 308)
		d = d * ft_dpow(10, (17 - exp10) / 2) * ft_dpow(10, (17 - exp10) / 2 +
			(17 - exp10) % 2);
	else
		d = d * ft_dpow(10, 17 - exp10);
	if (FT_ABS(d) < 10e17 && d != 0)
		d = d + (d < 0 ? -1 : 1);
	ll = (u_int64_t)d;
	lll = ft_oddceil(ll, fq.q + 1, 0);
	if (ft_log10ull(lll) > ft_log10ull(ll))
	{
		lll /= 10;
		exp10++;
		sign_ceiled |= 0x1u;
	}
	exp10 -= d == 0 ? 0 : 1;
	return (ft_putformat_e(lll, fq, exp10, sign_ceiled));
}
