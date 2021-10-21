/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:20:15 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:20:16 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_seplen;

int		str_cmp_smart(char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str++ != *to_find++)
			return (0);
	}
	return (1);
}

char	**reallol(char **ans, int wordn, char *new_value)
{
	char	**nns;
	int		i;

	i = 0;
	nns = (char **)malloc(sizeof(char *) * (wordn + 1));
	while (i < wordn - 1)
	{
		nns[i] = ans[i];
		i++;
	}
	nns[i] = new_value;
	return (nns);
}

int		str_len_sp(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	**loop(char **ans, char *separator, char *str, int *wordn)
{
	int inword;

	inword = 0;
	while (*str)
	{
		if (str_cmp_smart(str, separator))
		{
			inword = 0;
			str += g_seplen;
		}
		else
		{
			if (inword == 0)
			{
				ans = reallol(ans, ++(*wordn), str);
				inword = 1;
			}
			str++;
		}
	}
	return (ans);
}

char	**ft_split(char *str, char *separator)
{
	int		wordn;
	char	**ans;

	wordn = 0;
	ans = (char **)malloc(sizeof(char *));
	g_seplen = str_len_sp(separator);
	if (g_seplen == 0)
	{
		while (*str)
			ans = reallol(ans, ++wordn, str++);
	}
	ans = loop(ans, separator, str, &wordn);
	ans[wordn] = 0;
	return (ans);
}
