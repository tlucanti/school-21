/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:03:35 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/27 21:03:37 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *next_ptr;

	while (begin_list != 0)
	{
		free_fct(begin_list->data);
		next_ptr = begin_list->next;
		begin_list->next = 0;
		free(begin_list);
		begin_list = next_ptr;
	}
}
