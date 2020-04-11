/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:29:13 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 15:44:27 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*s;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp)
	{
		s = tmp;
		free(tmp);
		tmp = s->next;
	}
	*begin_list = 0;
}
