/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:05:48 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:05:49 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *rng;
	int i;

	i = -1;
	if (min >= max)
		return (0);
	if (max - min < 0)
		return (0);
	rng = (int *)malloc(sizeof(int) * (max - min));
	if (rng == 0)
		return (0);
	while (++i < max - min)
		rng[i] = min + i;
	return (rng);
}
