/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:01:29 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/10 03:48:12 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** if the last piece doesnt work, erase it outta map
*/

static int		revert_map(t_game *game, t_piece *piece, int w, int h)
{
	int i;
	int j;

	j = 0;
	w = (h > 0 ? piece->width - 1 : w);
	while (j <= h)
	{
		i = 0;
		while (i <= w)
		{
			if (game->map[piece->y + j][piece->x + i] == piece->letter)
				game->map[piece->y + j][piece->x + i] = CEMPTY;
			i++;
		}
		j++;
	}
	return (0);
}

/*
** try to put the pieces on the map
*/

static int		add_to_map(t_game *game, t_piece *piece)
{
	int	i;
	int	j;
	int	letsgo;

	j = 0;
	letsgo = 1;
	if (game->map[piece->y][piece->x] != CEMPTY && piece->map[0][0] != CEMPTY)
		return (0);
	while (letsgo && j < piece->height)
	{
		i = 0;
		while (letsgo && i < piece->width)
		{
			if (game->map[piece->y + j][piece->x + i] != CEMPTY
					&& piece->map[j][i] != CEMPTY)
				letsgo = 0;
			else if (game->map[piece->y + j][piece->x + i] == CEMPTY)
				game->map[piece->y + j][piece->x + i] = piece->map[j][i];
			i = (letsgo) ? i + 1 : i;
		}
		j = (letsgo) ? j + 1 : j;
	}
	if (letsgo)
		return (1);
	return (revert_map(game, piece, i, j));
}

/*
** check if this is the solution
*/

static int		is_it_the_answer(t_game *game, t_piece *pc)
{
	if (!pc)
		return (1);
	pc->x = 0;
	pc->y = 0;
	while (pc->y + pc->height <= game->size)
	{
		pc->x = 0;
		while (pc->x + pc->width <= game->size)
		{
			if (add_to_map(game, pc))
			{
				if (is_it_the_answer(game, pc->next))
					return (1);
				else
					revert_map(game, pc, pc->width - 1, pc->height - 1);
			}
			pc->x++;
		}
		pc->y++;
	}
	return (0);
}

/*
** main solve and increase size in a loop if needed
*/

void			solve(t_game *game)
{
	int j;

	while (!is_it_the_answer(game, game->pieces))
	{
		game->size++;
		j = 0;
		while (j < game->size)
			ft_memset(game->map[j++], CEMPTY, game->size);
	}
}
