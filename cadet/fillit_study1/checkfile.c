/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:00:38 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/10 03:48:18 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_validchar(int c, int i)
{
	if (c == CEMPTY || c == CBLOCK
		|| ((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_neighbourhood(char *buf, int i)
{
	int res;

	if (i == 19)
		return (0);
	res = 0;
	if (buf[i] == CBLOCK)
	{
		if (i > 0 && buf[i - 1] == CBLOCK)
			res++;
		if (i < 19 && buf[i + 1] == CBLOCK)
			res++;
		if (i >= 5 && buf[i - 5] == CBLOCK)
			res++;
		if (i <= 14 && buf[i + 5] == CBLOCK)
			res++;
	}
	return (res + check_neighbourhood(buf, ++i));
}

static int		check_block(char *buf)
{
	int i;
	int nb_diez;
	int first_diez;
	int ret;

	i = 0;
	nb_diez = 0;
	while (buf[i] && is_validchar(buf[i], i) && nb_diez <= 4)
	{
		if (buf[i] == CBLOCK)
		{
			nb_diez++;
			if (nb_diez == 1)
				first_diez = i;
		}
		i++;
	}
	if (i >= 20 && !buf[i] && nb_diez == 4
		&& (ret = check_neighbourhood(buf, first_diez))
		&& (ret == 6 || ret == 8))
		return (1);
	else
		dp_error(2);
	return (0);
}

int				parse_file(t_game *game, char *file)
{
	int		fd;
	int		ret;
	int		lastret;
	char	buf[22];

	ret = 0;
	lastret = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		dp_error(2);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		lastret = ret;
		buf[ret] = '\0';
		if (ret >= 20 && check_block(buf))
			store_block(game, buf);
		else
			dp_error(2);
	}
	if (ret <= 0 && (lastret == 21 || !lastret))
		dp_error(2);
	return (1);
}
