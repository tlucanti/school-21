/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:02:33 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:02:34 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	push_front_st(t_list **begin_list, void *data)
{
	t_list *esp;

	esp = ft_create_elem(data);
	if (begin_list == 0x0)
		begin_list = &esp;
	else
	{
		esp->next = *begin_list;
		*begin_list = esp;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list *esp;

	esp = 0;
	while (size--)
		push_front_st(&esp, *strs++);
	return (esp);
}
