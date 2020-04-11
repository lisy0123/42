/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:39:03 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/08 01:58:39 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ft_btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}

void	call(t_btree *root, int cur_level, int *levels,
		void (*applyf)(void *item, int cur_level, int elem))
{
	int elem;

	elem = 1;
	if (levels[cur_level] == 1)
		elem = 0;
	else
		levels[cur_level] = 1;
	applyf(root->item, cur_level, elem);
	if (root->left)
		call(root->left, cur_level + 1, levels, applyf);
	if (root->right)
		call(root->right, cur_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int	count;
	int	*levels;
	int	i;

	if (!root)
		return ;
	count = ft_btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	call(root, 0, levels, applyf);
}
