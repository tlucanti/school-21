/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconcept <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:19:03 by aconcept          #+#    #+#             */
/*   Updated: 2020/08/15 21:10:19 by aconcept         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		input(int a, int b, int *c, int *d)
{
	if (*c == 1 && *d == 1)
		ft_putchar('A');
	else if ((*c == 1 && *d == b) || (*c == a && *d == 1))
		ft_putchar('C');
	else if (*c == a && *d == b)
		ft_putchar('A');
	else if (*c == 1 || *c == a || *d == 1 || *d == b)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void		rush(int a, int b)
{
	int c;
	int d;

	c = 1;
	d = 1;
	while (b >= d)
	{
		while (a >= c)
		{
			input(a, b, &c, &d);
			c++;
		}
		d++;
		ft_putchar('\n');
		c = 1;
	}
}
