/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbrf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:51:39 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:51:40 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_puthexnbrf(unsigned long long n, const char *alphabet,
	t_format_qualifiers form_qua)
{
	char	buff[16];
	int		i;

	if (form_qua.o && n)
		return (ft_putaddressf((void *)n, alphabet, form_qua));
	i = 16;
	form_qua.z = (char)(form_qua.q == -1 ? form_qua.z : 32);
	buff[15] = (char)(48 * (form_qua.q != 0 && (n == 0) ? (--i * 0 + 1) : 1));
	while (n)
		n /= (buff[--i] = alphabet[n % 16]) * 0 + 16;
	i = 16 - i;
	form_qua.q = form_qua.q == -1 ? i : form_qua.q;
	if (form_qua.a == 0)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (FT_MAX(form_qua.q, i)), 0));
	ft_pns((char *)"0", FT_MAX(form_qua.q - i, 0));
	write(1, buff + 16 - i, i);
	if (form_qua.a == 1)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (FT_MAX(form_qua.q, i)), 0));
	return (FT_MAX3(form_qua.w, form_qua.q, i));
}
