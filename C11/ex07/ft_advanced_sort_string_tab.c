/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:45:03 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:45:04 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap_array(char **tab, int a, int b)
{
	char *c;

	c = tab[a];
	tab[a] = tab[b];
	tab[b] = c;
}

int		end_ast(char **tab)
{
	int i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;

	i = end_ast(tab);
	while (i)
	{
		j = 0;
		while (j < i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				swap_array(tab, j, j + 1);
			j++;
		}
		i--;
	}
}
