/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:20:14 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:20:16 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*at_rv(t_list *begin_list, unsigned int nbr)
{
	while (nbr-- && begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}

int		size_rv(t_list *begin_list)
{
	int i;

	if (begin_list == 0)
		return (0);
	i = 0;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i + 1);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	void	*data;
	int		i;
	t_list	*el;

	i = 0;
	size = size_rv(begin_list);
	while (i < size / 2)
	{
		el = at_rv(begin_list, size - 2 * i - 1);
		data = begin_list->data;
		begin_list->data = el->data;
		el->data = data;
		i++;
		begin_list = begin_list->next;
	}
}
