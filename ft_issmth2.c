/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issmth2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:14:24 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/16 12:42:33 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c__)
{
	return (ft_isalpha(c__) || ft_isdigit(c__));
}

int		ft_isascii(int c__)
{
	return (c__ >= 0 && c__ <= 127);
}

int		ft_isprint(int c__)
{
	return (c__ >= 32 && c__ <= 126);
}

int		ft_toupper(int c__)
{
	if (ft_islower(c__))
		return (c__ - 32);
	return (c__);
}

int		ft_tolower(int c__)
{
	if (ft_isupper(c__))
		return (c__ + 32);
	return (c__);
}
