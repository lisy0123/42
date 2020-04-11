/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:00:11 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 17:55:49 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *begin_list;
	b = NULL;
	c = NULL;
	while (a)
	{
		if ((*cmp)(a->data, data_ref) == 0)
		{
			if (a == *begin_list)
				*begin_list = a->next;
			else
				b->next = a->next;
			c = a;
			a = a->next;
			free(c);
		}
		else
		{
			b = a;
			a = a->next;
		}
	}
}
