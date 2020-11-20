/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:00:34 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/09 19:01:25 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(size_t a1__, size_t a2__)
{
	if (a1__ > a2__)
		return (a1__);
	return (a2__);
}

int		ft_min(size_t a1__, size_t a2__)
{
	if (a1__ < a2__)
		return (a1__);
	return (a2__);
}

int		ft_abs(int a__)
{
	if (a__ < 0)
		return (-a__);
	return (a__);
}
