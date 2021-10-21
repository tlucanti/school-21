/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:35:54 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:35:55 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	clear_t_list(t_list *begin_list)
{
	t_list *next_ptr;

	while (begin_list != 0)
	{
		next_ptr = begin_list->next;
		free(begin_list->number);
		free(begin_list->digit_name);
		free(begin_list);
		begin_list = next_ptr;
	}
}

void	clear_t_outl(t_outl *begin_list)
{
	t_outl *next_ptr;

	while (begin_list != 0)
	{
		next_ptr = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = next_ptr;
	}
}
