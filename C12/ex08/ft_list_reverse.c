/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:04:43 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:04:45 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *next;
	t_list *esp;
	t_list *begin_list_esp;

	if (begin_list == 0)
		return ;
	if ((*begin_list) == 0)
		return ;
	prev = *begin_list;
	esp = *begin_list;
	begin_list_esp = *begin_list;
	while (*begin_list)
	{
		esp = *begin_list;
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = next;
	}
	*begin_list = esp;
	begin_list_esp->next = 0;
}
