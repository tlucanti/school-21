/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:51:31 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 18:51:32 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_log10(double d)
{
	int exp;

	exp = 0;
	if (!VALID_DOUBLE(d) || d == 0)
		return (0);
	if (d >= 1)
	{
		while (d >= 1)
		{
			d /= 10;
			exp++;
		}
		return (exp);
	}
	else
	{
		while (d + (exp < -9 ? EPS : 0) < 1)
		{
			d *= 10;
			exp--;
		}
		return (exp + 1);
	}
}

int			ft_log10ull(uint64_t d)
{
	int exp;

	exp = 0;
	while (d)
	{
		exp++;
		d /= 10;
	}
	return (exp);
}

double		ft_dpow(double d, int16_t n)
{
	double dd;

	if (n < 0)
		return (1 / ft_dpow(d, -n));
	else if (n == 0)
		return (1);
	else if (n % 2)
		return (d * ft_dpow(d, n - 1));
	else
	{
		dd = ft_dpow(d, n / 2);
		return (dd * dd);
	}
}

u_int64_t	ft_ullpow(u_int64_t d, int16_t n)
{
	u_int64_t dd;

	if (n <= 0)
		return (1);
	else if (n % 2)
		return (d * ft_ullpow(d, n - 1));
	else
	{
		dd = ft_ullpow(d, n / 2);
		return (dd * dd);
	}
}

u_int16_t	ft_dnum(u_int64_t ll)
{
	u_int16_t dn;

	if (ll == 0)
		return (1);
	dn = 0;
	while (ll)
	{
		ll /= 10;
		dn++;
	}
	return (dn);
}
