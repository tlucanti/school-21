/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:52:02 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 18:52:05 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

u_int64_t	ft_oddceil(u_int64_t ll, u_int16_t q, int16_t exp10)
{
	u_int16_t	dn;
	int16_t		to_remove;

	dn = ft_dnum(ll);
	to_remove = dn - exp10 - q;
	if (to_remove <= 0 || to_remove > MAX_ACCURACY)
		return (ll);
	ll /= ft_ullpow(10, to_remove - 1);
	if ((ll / 10) % 2 || (ll % 10) > 5)
		ll += 5;
	ll /= 10;
	return (ll * ft_ullpow(10, to_remove));
}

int64_t		ft_putll(u_int64_t n, int dot, long long q, u_int16_t clt)
{
	u_int8_t	buff[17];
	u_int16_t	i;
	u_int64_t	cnt;

	buff[16] = 0;
	i = 16;
	cnt = 0;
	while (i)
	{
		cnt += n > 0;
		buff[--i] = (u_int8_t)(n % 10 + 48);
		n /= 10;
	}
	if (dot > 16)
		return (write(1, buff, 16) + ft_pns("0", dot - 16) +
			write(1, ".", q > 0) + ft_pns("0", q));
	else if (dot > 0)
		return (write(1, buff + (clt ? cnt < 16 : 0), dot) + write(1, ".", q >
		0) + write(1, buff + dot + (clt ? cnt < 16 : 0), FT_MIN((16 - dot) *
		(q > 0), q)) + ft_pns("0", (q - 16 + dot) * (q > 0)));
	else
		return (write(1, "0", 1) + write(1, ".", q > 0) + ft_pns("0", FT_MIN(
		-dot, q)) + write(1, buff, FT_ABSNULL(FT_MIN(16, q + dot))) + ft_pns(
		"0", q - 16 + dot));
}

int64_t		ft_put3nbr(int16_t n)
{
	u_int8_t	cc;
	u_int8_t	count;

	count = 1;
	if (n == 0)
		return (write(1, "00", 2));
	if (n >= 100)
	{
		cc = (n / 100) % 10 + 48;
		count += write(1, &cc, 1);
	}
	if (n >= 10)
	{
		cc = (n / 10) % 10 + 48;
		count += write(1, &cc, 1);
	}
	if (n < 10)
		count += write(1, "0", 1);
	cc = n % 10 + 48;
	write(1, &cc, 1);
	return (count);
}

u_int16_t	ft_find_zeros(uint64_t ll, u_int32_t start, u_int32_t count)
{
	u_int8_t	buff[16];
	u_int16_t	i;
	u_int16_t	aq;
	u_int8_t	*ptr;

	i = 16;
	while (ll)
	{
		buff[--i] = (ll % 10) + 48;
		ll /= 10;
	}
	i = 0;
	aq = 0;
	ptr = buff + start - 1;
	while (count && i <= 16)
	{
		i++;
		if (FT_ISNOTNULL(*ptr))
			aq = i;
		count--;
		ptr++;
	}
	return (aq);
}
