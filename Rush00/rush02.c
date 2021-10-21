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

void		input(int w, int h, int *x, int *y)
{
	if ((*x == 1 && *y == 1) || (*x == w && *y == 1))
		ft_putchar('A');
	else if ((*x == 1 && *y == h) || (*x == w && *y == h))
		ft_putchar('C');
	else if (*x == 1 || *x == w || *y == 1 || *y == h)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void		rush(int h, int w)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (x <= w)
	{
		while (y <= h)
		{
			input(w, h, &x, &y);
			y++;
		}
		x++;
		ft_putchar('\n');
		y = 1;
	}
}
