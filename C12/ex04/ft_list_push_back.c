/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:00:35 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:00:36 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*list_last_pb(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	if (!begin_list->next)
		return (begin_list);
	while (begin_list->next->next)
		begin_list = begin_list->next;
	return (begin_list->next);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new;

	new = ft_create_elem(data);
	if (begin_list == 0x0)
		begin_list = &new;
	else if (*begin_list == 0x0)
		*begin_list = new;
	else
		list_last_pb(*begin_list)->next = new;
}
