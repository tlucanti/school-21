/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:19:30 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:19:31 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int s;
	int a;

	s = 0;
	i = -1;
	while (++i < length - 1)
	{
		a = sgn(f(tab[i], tab[i + 1]);
		if (s == 0)
			s = a;
		else if (a == 0)
			continue ;
		else if (a != s)
			return (0);
	}
	return (1);
}
