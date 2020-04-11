/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:43:01 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 21:10:54 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
