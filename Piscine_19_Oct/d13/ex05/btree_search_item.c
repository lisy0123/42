/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 00:35:33 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/08 01:18:15 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	void	*out;

	out = 0;
	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (!out || !((*cmpf)(root->item, data_ref)))
			out = root->item;
		if (!out)
			out = btree_search_item(root->right, data_ref, cmpf);
	}
	return (out);
}
