/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:08:57 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/12 20:09:00 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int a)
{
	char c;

	c = (char)a + 48;
	write(1, &c, 1);
}

int		defaults(int *nb)
{
	if (*nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	if (*nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (*nb < 0)
	{
		write(1, "-", 1);
		*nb = -(*nb);
		return (0);
	}
	else
	{
		return (0);
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	a[10];

	if (defaults(&nb))
	{
		return ;
	}
	i = 0;
	while (nb)
	{
		a[i++] = nb % 10;
		nb /= 10;
	}
	while (i > 0)
	{
		print_digit(a[--i]);
	}
}
