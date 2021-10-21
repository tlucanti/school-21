/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:07:02 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:07:03 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range_u(int min, int max)
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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
		return (0);
	*range = ft_range_u(min, max);
	if (*range)
		return (max - min);
	else
		return (-1);
}
