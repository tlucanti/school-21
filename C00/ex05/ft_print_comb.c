/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:08:15 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/12 20:08:22 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int a)
{
	char c;

	c = (char)a + 48;
	write(1, &c, 1);
}

void	show(int i, int j, int k)
{
	print_digit(i);
	print_digit(j);
	print_digit(k);
}

void	cycling(int i, int j, int k)
{
	while (i <= 9)
	{
		while (j <= 9)
		{
			while (k <= 9)
			{
				if (i == 0 & j == 1 & k == 2)
				{
					k++;
					continue;
				}
				write(1, ", ", 2);
				show(i, j, k);
				k++;
			}
			j++;
			k = j + 1;
		}
		i++;
		j = i + 1;
		k = j + 1;
	}
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	j = i + 1;
	k = j + 1;
	show(i, j, k);
	cycling(i, j, k);
	write(1, "\n", 1);
}
