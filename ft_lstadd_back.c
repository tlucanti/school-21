/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:37:31 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/17 14:43:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, void *content)
{
	if (lst == nullptr)
		return ;
	if (*lst == nullptr)
	{
		*lst = ft_lstnew(content);
		return ;
	}
	ft_lstend(*lst)->next = ft_lstnew(content);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == nullptr)
		return ;
	if (*lst == nullptr)
		*lst = new;
	else
		ft_lstend(*lst)->next = new;
}
