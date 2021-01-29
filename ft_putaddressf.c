/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddressf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:47:08 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:47:09 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_putaddressf(void *ptr, const char *alphabet,
	t_format_qualifiers fq)
{
	char	buff[16];
	int		i;

	i = (size_t)ptr == 0 && fq.q ? 15 : 16;
	buff[15] = 48;
	while ((size_t)ptr)
	{
		buff[--i] = alphabet[(size_t)ptr % 16];
		ptr = (void *)((size_t)ptr / 16);
	}
	i = 16 - i;
	if (fq.z == 48 && fq.q == -1)
	{
		fq.q = fq.w - 2;
		fq.w = 0;
	}
	fq.q = fq.q == -1 ? i : fq.q;
	if (fq.a == 0)
		ft_pns((char *)" ", FT_MAX(fq.w - (FT_MAX(fq.q, i) + 2), 0));
	write(1, alphabet + 16, 2);
	ft_pns((char *)"0", FT_MAX(fq.q - i, 0));
	write(1, buff + 16 - i, i);
	if (fq.a == 1)
		ft_pns((char *)" ", FT_MAX(fq.w - (FT_MAX(fq.q, i) + 2), 0));
	return (FT_MAX3(fq.w, fq.q + 2, i + 2));
}
