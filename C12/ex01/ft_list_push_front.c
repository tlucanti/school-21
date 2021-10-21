/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:59:19 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 20:59:21 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
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
