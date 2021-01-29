/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloatnbr_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:53:02 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 18:53:03 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putfloatnbrg(double d, t_format_qualifiers fq,
	int16_t exp10_16bit)
{
	u_int64_t	ll;
	double		d_cpy;
	uint64_t	lll;
	uint32_t	exp10;

	fq.q = fq.q == -1 ? 6 : fq.q;
	d_cpy = d;
	d = FT_ABS(d);
	if (17 - exp10_16bit > 308)
		d = d * ft_dpow(10, (17 - exp10_16bit) / 2) * ft_dpow(10,
			(17 - exp10_16bit) / 2 + (17 - exp10_16bit) % 2);
	else
		d = d * ft_dpow(10, 17 - exp10_16bit);
	d += (d < ft_dpow(10, 16)) ? 9 : 0;
	ll = (u_int64_t)d;
	lll = ft_oddceil(ll, fq.q == 0 ? 1 : fq.q, 0);
	exp10 = 0;
	exp10 |= (u_int16_t)exp10_16bit;
	exp10 |= (exp10 << 16u);
	if (ft_log10ull(lll) > ft_log10ull(ll))
	{
		lll /= 10;
		exp10++;
	}
	return (ft_g_switcher1(lll / 10, fq, exp10, d_cpy));
}

uint64_t	ft_g_switcher1(uint64_t lll, t_format_qualifiers fq,
	int32_t exp10, double d_cpy)
{
	u_int64_t	aqf;
	u_int64_t	aqe;

	if ((short)(exp10 & 0xffffu) > 16)
		aqe = ft_find_zeros(lll, 2, fq.q - 1);
	else if ((short)(exp10 & 0xffffu) > 0)
	{
		aqf = ft_find_zeros(lll, (short)(exp10 & 0xffffu) + 1, fq.q);
		aqe = ft_find_zeros(lll, 2, fq.q - 1);
	}
	else
	{
		aqf = ft_find_zeros(lll, 2, fq.q - 1) - (short)(exp10 & 0xffffu) + 1;
		aqe = ft_find_zeros(lll, 2, fq.q - 1);
	}
	if ((d_cpy != 0) && ((short)(exp10 & 0xffffu) <= -4 ||
		(short)(exp10 & 0xffffu) - 1 >= (fq.q == 0 ? 1 : fq.q)))
	{
		fq.q = (int64_t)(fq.o ? fq.q -
			FT_ABSNULL((short)(exp10 & 0xffff)) : aqe);
		return (ft_putfloatnbre(d_cpy, fq, exp10 >> 16u));
	}
	else
		return (ft_g_switcher2(d_cpy, fq, aqf, exp10));
}

uint64_t	ft_g_switcher2(double d_cpy, t_format_qualifiers fq,
	uint64_t aqf, u_int32_t exp10)
{
	if (d_cpy == 0)
	{
		fq.q = FT_ABSNULL(fq.q - 1);
		fq.q = fq.o ? fq.q : 0;
		return (ft_putfloatnbrf(d_cpy, fq, (short)(exp10 >> 16u)));
	}
	else
	{
		fq.q = (int64_t)(fq.o ? FT_ABSNULL(fq.q -
			FT_ABSNULL((short)(exp10 & 0xffff))) : aqf);
		return (ft_putfloatnbrf(d_cpy, fq, (short)(exp10 >> 16u)));
	}
}
