/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconcept <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:50:26 by aconcept          #+#    #+#             */
/*   Updated: 2020/08/16 20:40:14 by aconcept         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void        ft_putchar(char c);

void		input(int a, int b, int *c, int *d)
{
	if ((*c == 1 && *d == 1) || (*c == a && *d == 1))
		ft_putchar('o');
	else if ((*c == 1 && *d == b) || (*c == a && *d == b))
		ft_putchar('o');
	else if (*c == 1 || *c == a)
		ft_putchar('|');
	else if (*d == 1 || *d == b)
		ft_putchar('-');
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
