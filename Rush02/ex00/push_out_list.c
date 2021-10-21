/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_out_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:36:57 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:36:58 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	push_out_list(t_outl **begin_list, char *data)
{
	t_outl *new;

	new = create_elem_outl(data);
	if (begin_list == 0x0)
		begin_list = &new;
	else if (*begin_list == 0x0)
		*begin_list = new;
	else
		outl_last(*begin_list)->next = new;
}

t_outl	*outl_last(t_outl *begin_list)
{
	if (begin_list == 0)
		return (0);
	if (!begin_list->next)
		return (begin_list);
	while (begin_list->next->next)
		begin_list = begin_list->next;
	return (begin_list->next);
}

t_outl	*create_elem_outl(char *data)
{
	t_outl *list;

	list = (t_outl *)malloc(sizeof(t_outl));
	list->data = data;
	list->next = 0;
	return (list);
}
