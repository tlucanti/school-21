/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:08:37 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/12 20:08:46 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_byte(int a)
{
	int a1;
	int a2;

	a1 = (a / 10) + 48;
	a2 = (a % 10) + 48;
	write(1, &a1, 1);
	write(1, &a2, 1);
}

void	show(int i, int j)
{
	write(1, ", ", 2);
	write_byte(i);
	write(1, " ", 1);
	write_byte(j);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	write_byte(0);
	write(1, " ", 1);
	write_byte(1);
	while (i <= 99)
	{
		while (j <= 99)
		{
			if (i == 0 & j == i + 1)
			{
				j++;
				continue;
			}
			show(i, j);
			j++;
		}
		i++;
		j = i + 1;
	}
	write(1, "\n", 1);
}
