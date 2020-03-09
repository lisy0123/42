/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:01:22 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/09 14:32:54 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** make it better with letter mdf
*/

char			*buf_to_piece(char const *s, unsigned int start,
					size_t len, char l)
{
	char			*res;
	unsigned int	index;

	if (!s)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	index = 0;
	while (index < len)
	{
		if (s[start + index] == CBLOCK)
			res[index] = l;
		else
			res[index] = s[start + index];
		index++;
	}
	return (res);
}

/*
** round numbers square root up buddy ! (Pay your Beer for that func!)
*/

static int		sqrt_ceil(int nb)
{
	int sol;

	sol = 1;
	while (sol * sol < nb)
		sol++;
	return (sol);
}

/*
** set da DAMN map m8 !
*/

static int		set_map(t_game *game, int size)
{
	int i;

	if (!(game->map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(game->map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(game->map[i++], CEMPTY, size);
	}
	return (1);
}

/*
** get da game ready 2 g0 !
*/

int				init_game(t_game *game, char *file)
{
	game->pieces = NULL;
	game->nb_pieces = 0;
	game->map = NULL;
	if (parse_file(game, file))
	{
		set_map(game, 4 * game->nb_pieces);
		game->size = 2 * sqrt_ceil(game->nb_pieces) - 1;
		return (1);
	}
	return (0);
}
