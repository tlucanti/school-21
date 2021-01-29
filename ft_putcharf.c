/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:50:24 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/25 11:50:27 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putcharf(char c, t_format_qualifiers form_qua)
{
	char	cc;

	if (form_qua.a == 0)
		ft_pns(&form_qua.z, FT_MAX(0, form_qua.w - 1));
	cc = c;
	write(1, &cc, 1);
	if (form_qua.a == 1)
		ft_pns(&form_qua.z, FT_MAX(0, form_qua.w - 1));
	return (FT_MAX(1, form_qua.w));
}
