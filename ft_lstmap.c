/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:03:55 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/17 15:16:06 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;

	del (0);
	if (lst == NULLPTR)
		return (NULLPTR);
	root = 0;
	while (lst)
	{
		ft_lstpushback(&root, f(lst->content));
		lst = lst->next;
	}
	return (root);
}
