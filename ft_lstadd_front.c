/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:26:55 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/17 14:55:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **lst, void *content)
{
	t_list	*root;

	if (lst == nullptr)
		return ;
	root = ft_lstnew(content);
	root->next = *lst;
	*lst = root;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == nullptr)
		return ;
	new->next = *lst;
	*lst = new;
}
