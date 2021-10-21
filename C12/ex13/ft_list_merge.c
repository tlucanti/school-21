/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:13:09 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:13:11 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*list_last_mr(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 == 0)
		begin_list1 = &begin_list2;
	else if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
		list_last_mr(*begin_list1)->next = begin_list2;
}
