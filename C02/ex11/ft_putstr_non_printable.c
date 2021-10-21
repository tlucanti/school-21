/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:37:26 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 19:37:28 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_array(char *arr)
{
	int i;

	i = 0;
	while (i < 10)
	{
		arr[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		arr[i] = i - 10 + 'a';
		i++;
	}
}

void	print_hex(char n)
{
	char a1;
	char a2;
	char hexes[16];

	init_array(hexes);
	a1 = hexes[n / 0x10];
	a2 = hexes[n % 0x10];
	write(1, "\\", 1);
	write(1, &a1, 1);
	write(1, &a2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 | *str > 126)
		{
			print_hex(*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
