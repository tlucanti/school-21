/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstrf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:05:05 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 12:05:06 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putnstrf(char *str, t_format_qualifiers form_qua)
{
	size_t	s_len;

	if (str == NULL)
		str = "(null)";
	s_len = FT_STRLEN(str);
	form_qua.q = form_qua.q == -1 ? (long long)s_len : form_qua.q;
	s_len = FT_MIN((long long)s_len, form_qua.q);
	if (form_qua.a == 0)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (long long)s_len, 0));
	write(1, str, s_len);
	if (form_qua.a == 1)
		ft_pns(&form_qua.z, FT_MAX(form_qua.w - (long long)s_len, 0));
	return ((int)FT_MAX(form_qua.w, (long)s_len));
}
