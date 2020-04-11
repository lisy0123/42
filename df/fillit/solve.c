/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:27:12 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/10 03:50:55 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		back_map(t_frame *frame, t_piece *piece, int w, int h)
{
	int			i;
	int			j;

	i = 0;
	w = (h > 0 ? piece->w - 1 : w);
	while (i <= h)
	{
		j = 0;
		while (j <= w)
		{
			if (frame->f_map[piece->y + i][piece->x + j] == piece->letter)
				frame->f_map[piece->y + i][piece->x + j] = EMPTY;
			j++;
		}
		i++;
	}
	return (0);
}

static int		add_map(t_frame *frame, t_piece *p)
{
	int			i;
	int			j;
	int			stop;

	i = 0;
	stop = 1;
	if (frame->f_map[p->y][p->x] != EMPTY && p->p_map[0][0] != EMPTY)
		return (0);
	while (stop && i < p->h)
	{
		j = 0;
		while (stop && j < p->w)
		{
			if (frame->f_map[p->y + i][p->x + j] != EMPTY
					&& p->p_map[i][j] != EMPTY)
				stop = 0;
			else if (frame->f_map[p->y + i][p->x + j] == EMPTY)
				frame->f_map[p->y + i][p->x + j] = p->p_map[i][j];
			j = (stop) ? j + 1 : j;
		}
		i = (stop) ? i + 1 : i;
	}
	if (stop)
		return (1);
	return (back_map(frame, p, j, i));
}

static int		answer(t_frame *frame, t_piece *p)
{
	if (!p)
		return (1);
	p->x = 0;
	p->y = 0;
	while (p->y + p->h <= frame->size)
	{
		p->x = 0;
		while (p->x + p->w <= frame->size)
		{
			if (add_map(frame, p))
			{
				if (answer(frame, p->next))
					return (1);
				else
					back_map(frame, p, p->w - 1, p->h - 1);
			}
			p->x++;
		}
		p->y++;
	}
	return (0);
}

void			solve(t_frame *frame)
{
	int			j;

	while (!answer(frame, frame->pieces))
	{
		frame->size++;
		j = 0;
		while (j < frame->size)
			ft_memset(frame->f_map[j++], EMPTY, frame->size);
	}
}
