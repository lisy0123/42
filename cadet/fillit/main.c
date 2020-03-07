/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:28:27 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/05 15:07:15 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

read_fd(int fd)
{
}

void	dsiplay(int fd)
{
	solve(read_fd(int fd));
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr("usage : fillit source file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	display(fd);
	close(fd);
	return (0);
}
