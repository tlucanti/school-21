/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctnbrf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:06:27 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 12:06:28 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_putoctnbrf(unsigned long long n, const char *alphabet,
	t_format_qualifiers form_qua)
{
	char	buff[23];
	int		i;

	i = 23;
	form_qua.z = (char)(form_qua.q == -1 ? form_qua.z : 32);
	buff[22] = (char)(48 * (form_qua.q != 0 && (n == 0) ? (--i * 0 + 1) : 1));
	form_qua.o = (char)(n == 0 ? (form_qua.q == 0) : form_qua.o);
	while (n)
		n /= (buff[--i] = alphabet[n % 8]) * 0 + 8;
	i -= (buff[i - 1] = 48) * 0 + form_qua.o;
	i = 23 - i;
	form_qua.q = form_qua.q == -1 ? i : form_qua.q;
	if (form_qua.a == 0)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (FT_MAX(form_qua.q, i)), 0));
	ft_pns("0", FT_MAX(form_qua.q - i, 0));
	write(1, buff + 23 - i, i);
	if (form_qua.a == 1)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (FT_MAX(form_qua.q, i)), 0));
	return (FT_MAX3(form_qua.w, form_qua.q, i));
}
