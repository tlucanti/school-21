/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:11:51 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/28 23:11:52 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	insert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!*root)
		*root = btree_create_node(item);
	else if (cmpf(item, (*root)->item) < 0)
		insert(&((*root)->left), item, cmpf);
	else if (cmpf(item, (*root)->item) >= 0)
		insert(&((*root)->right), item, cmpf);
}

void	btree_insert_data(t_btree **root,
	void *item, int (*cmpf)(void *, void *))
{
	t_btree *r00t;

	if (!root)
		return ;
	r00t = *root;
	if (!*root)
		*root = btree_create_node(item);
	else
	{
		insert(root, item, cmpf);
		*root = r00t;
	}
}
