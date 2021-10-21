/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:23:35 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/22 19:23:38 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

void	print_int(int nb)
{
	int		i;
	char	a[10];
	char	c;

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
		c = a[--i] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		print_str(par->str);
		print_int(par->size);
		print_str(par->copy);
		par++;
	}
}
