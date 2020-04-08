/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:47:31 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 22:03:24 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*temp;

	if (*begin_list1)
	{
		temp = *begin_list1;
		while (temp->next)
			temp = temp->next;
		temp->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *begin_list;
	if (a)
	{
		b = *begin_list;
		while (b->next)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
			{
				c = b->data;
				b->data = b->next->data;
				b->next->data = c;
			}
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
