/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:44:09 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:44:11 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		str_cmp_st(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			break ;
	return (*--s1 - *--s2);
}

void	swap_tabay(char **tab, int a, int b)
{
	char *c;

	c = tab[a];
	tab[a] = tab[b];
	tab[b] = c;
}

int		end_st(char **tab)
{
	int i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;

	i = end_st(tab);
	while (i)
	{
		j = 0;
		while (j < i - 1)
		{
			if (str_cmp_st(tab[j], tab[j + 1]) > 0)
				swap_tabay(tab, j, j + 1);
			j++;
		}
		i--;
	}
}
