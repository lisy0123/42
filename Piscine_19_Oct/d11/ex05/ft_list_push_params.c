/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:27:15 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/06 19:29:43 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*t;
	t_list	*s;
	int		i;

	if (ac <= 0)
		return (0);
	i = 0;
	t = NULL;
	while (i < ac)
	{
		s = ft_create_elem(av[i]);
		s->next = t;
		t = s;
		i++;
	}
	return (s);
}
