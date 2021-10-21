/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:05:38 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/18 12:06:19 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_str_putnbr(char *str, int *bas)
{
	char hash[256];

	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (0);
		hash[(int)*str]++;
		if (hash[(int)*str] == 2)
			return (0);
		str++;
		(*bas)++;
	}
	if (*bas <= 1)
		return (0);
	return (1);
}

int		defaults_putnbr_base(int *nbr)
{
	if (*nbr < 0)
	{
		write(1, "-", 1);
		*nbr = -(*nbr);
	}
	if (*nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	buffer[33];
	int		digits;
	int		bas;

	digits = 0;
	bas = 0;
	if (!check_str_putnbr(base, &bas))
		return ;
	if (nbr == -2147483648)
	{
		buffer[digits++] = base[nbr % bas];
		nbr /= bas;
	}
	if (defaults_putnbr_base(&nbr))
		return ;
	while (nbr)
	{
		buffer[digits++] = base[nbr % bas];
		nbr /= bas;
	}
	while (digits)
		write(1, buffer + (--digits), 1);
}
