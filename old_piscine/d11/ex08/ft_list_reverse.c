/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:38:30 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 16:28:07 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#iclude "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = 0;
	b = 0;
	c = *begin_list;
	while (c)
	{
		b = c->next;
		c->next = a;
		a = c;
		c = b;
	}
	*begin_list = a;
}
