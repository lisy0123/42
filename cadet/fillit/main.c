/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:39:47 by tlee              #+#    #+#             */
/*   Updated: 2020/03/10 03:57:09 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			throw_error(int c)
{
	if (c == 1)
		ft_putstr(ERROR1);
	else if (c == 2)
		ft_putstr(ERROR2);
	exit(1);
}

static void		free_map(t_frame *frame)
{
	int			i;

	i = 0;
	if (frame->f_map)
	{
		while (i < 4 * frame->nb_piece)
			free(frame->f_map[i++]);
		free(frame->f_map);
		frame->f_map = NULL;
	}
}

static void		put_map(t_frame *frame)
{
	int			i;
	int			j;

	j = 0;
	while (j < frame->size)
	{
		i = 0;
		while (i < frame->size)
			ft_putchar(frame->f_map[j][i++]);
		ft_putchar('\n');
		j++;
	}
}

int				main(int argc, char **argv)
{
	t_frame frame;

	if (argc != 2)
	{
		throw_error(2);
		return (0);
	}
	if (reader(&frame, argv[1]))
	{
		solve(&frame);
		put_map(&frame);
		free_map(&frame);
	}
	else
		throw_error(1);
	return (1);
}
