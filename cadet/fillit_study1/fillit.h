/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:01:13 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/09 14:31:53 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

# define CBLOCK '#'
# define CEMPTY '.'

# define ERR1 "usage: ./fillit source_file\n"
# define ERR2 "error\n"

typedef struct		s_coord
{
	int t;
	int r;
	int b;
	int l;
}					t_coord;

typedef struct		s_piece
{
	int				x;
	int				y;
	int				width;
	int				height;
	char			**map;
	char			letter;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_game
{
	t_piece		*pieces;
	int			nb_pieces;
	int			size;
	char		**map;
}					t_game;

void				put_map(t_game *game);
void				dp_error(int c);
int					parse_file(t_game *game, char *file);
int					init_game(t_game *game, char *file);
void				store_block(t_game *game, char *buf);
void				pushback_piece(t_game *game, t_piece *piece);
void				solve(t_game *game);
char				*buf_to_piece(char const *s, unsigned int start,
						size_t len, char l);

#endif
