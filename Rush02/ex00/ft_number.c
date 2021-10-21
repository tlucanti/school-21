/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:56:25 by droslyn           #+#    #+#             */
/*   Updated: 2020/08/30 18:51:36 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_rank_str(int size)
{
	char	*s_rank;
	char	*ptr_rank;

	if (!(s_rank = malloc(sizeof(char) * size + 2)))
		return (s_rank);
	ptr_rank = s_rank;
	*s_rank = '1';
	s_rank++;
	size--;
	while (size)
	{
		*s_rank = '0';
		s_rank++;
		size--;
	}
	*s_rank = '\0';
	return (ptr_rank);
}

int		ft_print_error(void)
{
	write(2, "Dict Error\n", 11);
	return (1);
}

int		ft_million(int length)
{
	char *rank_ch;

	if (!(rank_ch = ft_rank_str(length)))
		return (1);
	if (request(rank_ch))
		return (ft_print_error());
	free(rank_ch);
	return (0);
}

int		ft_number(char *str, int len)
{
	while (*str)
	{
		while (*str == '0')
		{
			str++;
			len--;
		}
		if (len % 3 == 0 && *str != '0' && (ft_hundred(str) != 0))
			return (1);
		else if (len % 3 == 2 && *str != '0')
		{
			if (ft_decimals(str, len))
				return (1);
			str++;
			len--;
		}
		else if (len % 3 == 1 && *str != '0' && (ft_units(str, len) != 0))
			return (1);
		str++;
		len--;
	}
	return (0);
}
