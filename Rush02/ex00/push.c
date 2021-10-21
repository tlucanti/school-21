/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:36:48 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:36:49 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	push(t_list **begin_list, char *str1, char *str2, int num)
{
	t_list *new;

	new = create_elem(str1, str2, num);
	if (begin_list == 0x0)
		begin_list = &new;
	else if (*begin_list == 0x0)
		*begin_list = new;
	else
		list_last_pb(*begin_list)->next = new;
}

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

t_list	*create_elem(char *str1, char *str2, int num)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->number = str1;
	list->digit_name = str2;
	list->next = 0;
	list->size = num;
	return (list);
}
