/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:38:38 by tlee              #+#    #+#             */
/*   Updated: 2020/03/10 04:00:02 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		sqrt_size(int nb)
{
	int sol;

	sol = 1;
	while (sol * sol < nb)
		sol++;
	return (sol);
}

static int		set_map(t_frame *frame, int size)
{
	int i;

	if (!(frame->f_map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(frame->f_map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(frame->f_map[i++], EMPTY, size);
	}
	return (1);
}

int				reader(t_frame *frame, char *file)
{
	frame->pieces = NULL;
	frame->nb_piece = 0;
	frame->f_map = NULL;
	if (check_file(frame, file))
	{
		set_map(frame, 4 * frame->nb_piece);
		frame->size = 2 * sqrt_size(frame->nb_piece) - 1;
		return (1);
	}
	return (0);
}
