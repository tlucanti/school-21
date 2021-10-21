/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:07:07 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:07:09 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list *prev;
	t_list *next;
	t_list *esp;
	t_list *begin_list_esp;

	prev = 0;
	esp = *begin_list;
	begin_list_esp = *begin_list;
	while (esp)
	{
		next = esp->next;
		if (!cmp(esp->data, data_ref))
		{
			free_fct(esp->data);
			if (prev == 0)
				begin_list_esp = next;
			else
				prev->next = next;
			free(esp);
		}
		prev = esp;
		esp = next;
	}
	*begin_list = begin_list_esp;
}
