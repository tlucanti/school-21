/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:53:31 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:53:32 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_putnmbrf(unsigned long long n,
	t_format_qualifiers fq, int sgn)
{
	char	buff[20];
	int		i;

	sgn = sgn ? (int)(n >> 63u) : 0;
	i = 20;
	n = sgn ? ((-2) * sgn + 1) * n : n;
	fq.s = (char)(fq.s == '+' ? '+' * !sgn + '-' * sgn : fq.s);
	i -= (buff[19] = 48) * 0 + (n == 0 && fq.q != 0);
	while (n)
		n /= (buff[--i] = (char)(n % 10 + 48)) * 0 + 10;
	i = 20 - i;
	fq.w -= (fq.s != 0 && !sgn);
	if (fq.z == 48 && fq.q == -1)
	{
		fq.q = fq.w - sgn;
		fq.w = 0;
	}
	fq.q = fq.q == -1 ? 0 : fq.q;
	ft_pns((char *)" ", (fq.w - FT_MAX(fq.q, i) - sgn) * (fq.a == 0));
	write(1, sgn ? (char *)"-" : &fq.s, sgn || fq.s);
	ft_pns((char *)"0", fq.q - i);
	write(1, buff + 20 - i, i);
	ft_pns((char *)" ", (fq.w - FT_MAX(fq.q, i) - sgn) * (fq.a != 0));
	return ((int)FT_MAX3(i + (fq.s != 0 || sgn), fq.w + (fq.s != 0 && !sgn),
		fq.q + (sgn || fq.s != 0)));
}
