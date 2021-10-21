/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:19:25 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:19:27 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		size_srt(t_list *begin_list)
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

void	swap_array(t_list *prev, t_list *esp, t_list **begin_list)
{
	t_list *nn;
	t_list *next;

	next = esp->next;
	if (next->next == 0)
	{
		esp->next = 0;
		next->next = esp;
		if (prev != 0)
			prev->next = next;
	}
	else
	{
		nn = next->next;
		next->next = esp;
		esp->next = nn;
		if (prev != 0)
			prev->next = next;
	}
	if (prev == 0)
		*begin_list = next;
}

void	update_values(int *j, int *unsorted, t_list **prev)
{
	*j = -1;
	*unsorted = *unsorted - 1;
	*prev = 0;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		unsorted;
	int		j;
	t_list	*esp;
	t_list	*prev;

	j = -1;
	prev = 0;
	esp = *begin_list;
	unsorted = size_srt(*begin_list);
	while (unsorted > 1)
	{
		while (++j < unsorted - 1)
		{
			if (cmp(esp->data, esp->next->data) < 0)
				swap_array(prev, esp, begin_list);
			else
				esp = esp->next;
			if (prev == 0)
				prev = *begin_list;
			else
				prev = prev->next;
		}
		update_values(&j, &unsorted, &prev);
		esp = *begin_list;
	}
}
