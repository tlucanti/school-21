/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:13:11 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/28 23:13:12 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int l;
	int r;

	if (!root)
		return (0);
	l = 1 * (root->left || 0) + btree_level_count(root->left);
	r = 1 * (root->right || 0) + btree_level_count(root->right);
	return (l > r ? l : r);
}
