/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 03:03:46 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 19:59:08 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_char				*ft_create_elem(void)
{
	t_char *list_char;

	list_char = (t_char *)malloc(sizeof(t_char));
	list_char->character = 0;
	list_char->next = NULL;
	return (list_char);
}

void				ft_list(t_char *list_start)
{
	while (list_start->next)
	{
		write(1, &list_start->character, 1);
		list_start = list_start->next;
	}
}

void				ft_results(int *res, int col, int line)
{
	int				i;
	int				p;

	i = 0;
	p = 0;
	while (i < 5)
	{
		if (res[i])
		{
			if (p)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(col);
			ft_putstr("] [");
			ft_putnbr(line);
			ft_putstr("]");
			p = 1;
		}
		i++;
	}
	if (!p)
		ft_putstr("aucune");
	write(1, "\n", 1);
}

int					main(void)
{
	t_char			*list;
	t_char			*start;
	char			**compare;
	int				*res;

	list = ft_create_elem();
	start = list;
	while (read(0, &list->character, 1))
	{
		list->next = ft_create_elem();
		list = list->next;
	}
	compare = ft_call(ft_col(start), ft_lines(start));
	res = ft_compare(compare, start);
	ft_results(res, ft_col(start), ft_lines(start));
	return (0);
}
