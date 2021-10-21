/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:46:16 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 22:46:17 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list *begin_list1_esp;
	t_list *nn;
	t_list *nbl;

	begin_list1_esp = *begin_list1;
	while ((*begin_list1)->next && begin_list2)
	{
		if (cmp((*begin_list1)->data, begin_list2->data) >= 0 &&
			cmp(begin_list2->data, (*begin_list1)->data) >= 0)
		{
			nn = (*begin_list1)->next;
			nbl = begin_list2->next;
			(*begin_list1)->next = begin_list2;
			begin_list2->next = nn;
			begin_list2->next = nbl;
		}
		*begin_list1 = (*begin_list1)->next;
		begin_list2 = begin_list2->next;
	}
	if (!(*begin_list1)->next && begin_list2)
		(*begin_list1)->next = begin_list2;
	*begin_list1 = begin_list1_esp;
}
