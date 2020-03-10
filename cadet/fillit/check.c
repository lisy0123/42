/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:39:11 by tlee              #+#    #+#             */
/*   Updated: 2020/03/10 03:58:57 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(int c, int i)
{
	if (c == EMPTY || c == BLOCK
			|| ((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_side(char *buf, int i)
{
	int res;

	if (i == 19)
		return (0);
	res = 0;
	if (buf[i] == BLOCK)
	{
		if (i > 0 && buf[i - 1] == BLOCK)
			res++;
		if (i < 19 && buf[i + 1] == BLOCK)
			res++;
		if (i >= 5 && buf[i - 5] == BLOCK)
			res++;
		if (i <= 14 && buf[i + 5] == BLOCK)
			res++;
	}
	return (res + check_side(buf, ++i));
}

static int		check_block(char *buf)
{
	int i;
	int nb_p;
	int first_p;
	int ret;

	i = 0;
	nb_p = 0;
	while (buf[i] && is_valid(buf[i], i) && nb_p <= 4)
	{
		if (buf[i] == BLOCK)
		{
			nb_p++;
			if (nb_p == 1)
				first_p = i;
		}
		i++;
	}
	if (i >= 20 && !buf[i] && nb_p == 4
		&& (ret = check_side(buf, first_p)) && (ret == 6 || ret == 8))
		return (1);
	else
		throw_error(1);
	return (0);
}

int				check_file(t_frame *frame, char *file)
{
	int		fd;
	int		ret;
	int		lastret;
	char	buf[22];

	ret = 0;
	lastret = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		throw_error(1);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		lastret = ret;
		buf[ret] = '\0';
		if (ret >= 20 && check_block(buf))
			save_block(frame, buf);
		else
			throw_error(1);
	}
	if (ret <= 0 && (lastret == 21 || !lastret))
		throw_error(1);
	return (1);
}
