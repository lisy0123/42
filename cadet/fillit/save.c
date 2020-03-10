/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:07:37 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/10 03:58:48 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*buf_piece(char const *s, unsigned int start,
						size_t len, char letter)
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
		if (s[start + index] == BLOCK)
			res[index] = letter;
		else
			res[index] = s[start + index];
		index++;
	}
	return (res);
}

static t_pos		get_pos(char *buf)
{
	t_pos			pos;
	int				index;

	pos.h_d = 3;
	pos.h_u = 0;
	pos.w_d = 3;
	pos.w_u = 0;
	index = 0;
	while (buf[index])
	{
		if (buf[index] == BLOCK)
		{
			if (index / 5 < pos.h_d)
				pos.h_d = index / 5;
			if (index / 5 > pos.h_u)
				pos.h_u = index / 5;
			if (index % 5 < pos.w_d)
				pos.w_d = index % 5;
			if (index % 5 > pos.w_u)
				pos.w_u = index % 5;
		}
		index++;
	}
	return (pos);
}

static t_piece		*setting_piece(char *buf)
{
	t_piece			*new;
	t_pos			pos;
	int				i;
	static char		c = 'A';

	if (!(new = ft_memalloc(sizeof(t_piece))))
		throw_error(1);
	new->x = 0;
	new->y = 0;
	new->letter = c++;
	new->next = NULL;
	pos = get_pos(buf);
	new->w = pos.w_u - pos.w_d + 1;
	new->h = pos.h_u - pos.h_d + 1;
	if (!(new->p_map = (char **)malloc(new->h * sizeof(char *))))
		throw_error(1);
	i = 0;
	while (i < new->h)
	{
		new->p_map[i] = buf_piece(buf,
				((pos.h_d + i) * 5 + pos.w_d), new->w, new->letter);
		i++;
	}
	return (new);
}

static void			putback_piece(t_frame *frame, t_piece *piece)
{
	t_piece			*lst;

	lst = frame->pieces;
	if (!lst)
	{
		frame->pieces = piece;
		frame->nb_piece++;
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = piece;
	frame->nb_piece++;
}

void				save_block(t_frame *frame, char *buf)
{
	t_piece	*new;

	new = setting_piece(buf);
	putback_piece(frame, new);
}
