/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:31:41 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 22:31:43 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*list_last_16(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

int		defaults(t_list **begin_list, void *data, int (*cmp)(), t_list *new)
{
	t_list *nn;

	nn = ((*begin_list)->next);
	if (cmp(data, (*begin_list)->data) >= 0)
	{
		new->next = (*begin_list)->next;
		*begin_list = new;
		return (1);
	}
	nn = list_last_16(*begin_list);
	if (cmp((nn)->data, data) >= 0)
	{
		nn->next = new;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *new;
	t_list *nn;
	t_list *begin_list_esp;

	if (begin_list == 0)
		return ;
	begin_list_esp = *begin_list;
	new = ft_create_elem(data);
	if (*begin_list == 0)
		return (void)(*begin_list = new);
	if (defaults(begin_list, data, cmp, new))
		return ;
	while ((*begin_list)->next)
	{
		if (cmp((*begin_list)->data, data) >= 0 &&
			cmp(data, (*begin_list)->data) >= 0)
		{
			nn = (*begin_list)->next;
			new->next = nn;
			(*begin_list)->next = new;
			*begin_list = (*begin_list)->next;
		}
		*begin_list = (*begin_list)->next;
	}
	*begin_list = begin_list_esp;
}
