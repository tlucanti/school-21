/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:22:42 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/13 19:22:48 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** Bubble sort, lol
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = size;
	while (i)
	{
		while (j < i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(tab + j, tab + j + 1);
			}
			j++;
		}
		i--;
		j = 0;
	}
}
