/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:18:45 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:18:47 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ans;
	int i;

	i = 0;
	ans = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		ans[i] = f(tab[i]);
		i++;
	}
	return (ans);
}
