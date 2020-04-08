/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:14:29 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 21:46:00 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;

	if (*begin_list)
	{
		temp = *begin_list;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
