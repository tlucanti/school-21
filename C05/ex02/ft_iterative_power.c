/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:42:10 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/19 12:42:12 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int s;

	s = 1;
	if (power < 0)
		return (0);
	if (nb <= 0 && power == 0)
		return (1);
	if (nb == 0 && nb > 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > 1 && power == 1)
		return (1);
	while (power--)
		s *= nb;
	return (s);
}
