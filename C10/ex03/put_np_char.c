/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_np_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:05:25 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 21:05:27 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	put_np_char(char c)
{
	if (c >= 32 && c <= 126)
	{
		write(1, "   ", 3);
		write(1, &c, 1);
	}
	else if (c == '\r')
		write(1, "  \\r", 4);
	else if (c == '\t')
		write(1, "  \\t", 4);
	else if (c == '\a')
		write(1, "  \\a", 4);
	else if (c == '\f')
		write(1, "  \\f", 4);
	else if (c == '\v')
		write(1, "  \\v", 4);
	else if (c == '\b')
		write(1, "  \\b", 4);
	else if (c == '\n')
		write(1, "  \\n", 4);
	else
		print_3_num((int)c);
}

void	print_3_num(int n)
{
	int ans;

	ans = 0;
	while (n)
	{
		ans = ans * 10 + n % 8;
		n /= 8;
	}
	print_81_num(ans);
}

void	print_81_num(int n)
{
	char c;

	if (n < 10)
	{
		write(1, " 00", 3);
		c = (char)(n + 48);
		write(1, &c, 1);
	}
	else if (n < 100)
	{
		write(1, " 0", 2);
		c = (char)(n % 10 + 48);
		write(1, &c, 1);
		c = (char)(n / 10 + 48);
		write(1, &c, 1);
	}
	else
		print_82_num(n);
}

void	print_82_num(int n)
{
	char c;

	write(1, " ", 1);
	c = (char)(n % 10 + 48);
	write(1, &c, 1);
	c = (char)((n / 10) % 10 + 48);
	write(1, &c, 1);
	c = (char)(n / 100 + 48);
	write(1, &c, 1);
}
