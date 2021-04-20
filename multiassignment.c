/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiassignment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:17:03 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/17 12:04:34 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	masi2(int *dest1, int source1, int *dest2, int source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}

int	masp2(t_point **dest1, t_point *source1, t_point **dest2, t_point *source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}

int	masp1(t_point **dest, t_point *source)
{
	*dest = source;
	return (1);
}

int	masf2(float *dest1, float source1, float *dest2, float source2)
{
	*dest1 = source1;
	*dest2 = source2;
	return (1);
}
