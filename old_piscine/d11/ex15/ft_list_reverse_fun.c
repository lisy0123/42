/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:58:22 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 21:13:24 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	int		count;
	t_list	*a;
	t_list	*b;

	count = 0;
	a = begin_list;
	while (a && ++count)
		a = a->next;
	i = 0;
	while (i < count - 1)
	{
		j = i;
		a = begin_list;
		while (a && a->next && j < couunt - 1)
		{
			b = a->data;
			a->data = a->next->data;
			a->next->data = b;
			a = a->next;
			j++;
		}
		i++;
	}
}
