/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:52:13 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 22:04:03 by sanlee           ###   ########.fr       */
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
