/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:02:36 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/10 04:00:55 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ERROR1 "error\n"
# define ERROR2 "usage: ./fillit source_file\n"
# define BLOCK '#'
# define EMPTY '.'
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_piece
{
	int				x;
	int				y;
	int				w;
	int				h;
	char			**p_map;
	char			letter;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_frame
{
	t_piece			*pieces;
	int				nb_piece;
	int				size;
	char			**f_map;
}					t_frame;

typedef struct		s_pos
{
	int				h_d;
	int				h_u;
	int				w_d;
	int				w_u;
}					t_pos;

void				throw_error(int i);
int					reader(t_frame *frame, char *file);
int					check_file(t_frame *frame, char *file);
void				save_block(t_frame *frame, char *buf);
void				solve(t_frame *frame);

#endif
