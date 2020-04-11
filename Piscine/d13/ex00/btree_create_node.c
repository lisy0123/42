/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:38:43 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/07 23:47:36 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree	*temp;

	temp = malloc(sizeof(temp));
	if (temp)
	{
		temp->item = item;
		temp->left = 0;
		temp->right = 0;
	}
	return (temp);
}
