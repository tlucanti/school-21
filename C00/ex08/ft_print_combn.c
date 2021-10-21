/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:35:35 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/13 13:35:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		digit_num(int a)
{
	int i;

	i = 0;
	if (a == 0)
	{
		return (1);
	}
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	print_int(int nb)
{
	char	a[10];
	int		i;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = 0;
	while (nb)
	{
		a[i++] = nb % 10;
		nb /= 10;
	}
	while (i > 0)
	{
		c = (char)(a[--i]) + 48;
		write(1, &c, 1);
	}
}

int		ascend(int num)
{
	int cur;
	int prev;

	cur = num % 10;
	while (num)
	{
		num /= 10;
		prev = cur;
		cur = num % 10;
		if (cur >= prev)
		{
			return (0);
		}
	}
	return (1);
}

void	show(int num, int n)
{
	int d_num;

	d_num = digit_num(num);
	while (n - d_num > 0)
	{
		write(1, "0", 1);
		n--;
	}
	print_int(num);
}

void	ft_print_combn(int n)
{
	int num;
	int power_10;
	int i;

	power_10 = 1;
	i = n;
	while (i--)
	{
		power_10 *= 10;
	}
	num = 1;
	show(num, n);
	num++;
	while (num < power_10)
	{
		if (ascend(num))
		{
			write(1, ", ", 2);
			show(num, n);
		}
		num++;
	}
	write(1, "\n", 1);
}
