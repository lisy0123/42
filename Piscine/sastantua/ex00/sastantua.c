/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:04:47 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/27 20:57:02 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	line(int space, int len)
{
	int i;

	i = 0;
	while (i++ < space)
		ft_putchar(' ');
	ft_putchar('/');
	i = 0;
	while (i++ < len)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	door(int space, int len, int d_size)
{
	int i;
	int y;

	i = 0;
	y = d_size;
	while (i++ < space)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < len)
		ft_putchar('*');
	i = 0;
	while (y--)
	{
		if (y == 1 && d_size / 2 == space && d_size > 3)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	while (i++ < len)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	build(int l_total, int size, int start_door)
{
	int c_floor;
	int c_line;
	int len;
	int shift;
	int space;

	c_floor = 0;
	len = -1;
	shift = 2;
	while (c_floor++ < size)
	{
		c_line = 1;
		while (c_line++ <= (c_floor + 2))
		{
			len = len + 1;
			space = ((l_total / 2) - len - 1);
			if (c_floor == size && c_line > (size + 3) - start_door)
				door(space, len - (start_door / 2), start_door);
			else
				line(space, (len * 2) + 1);
		}
		if (c_floor % 2 && c_floor > 1)
			shift++;
		len = shift + len;
	}
}

void	sastantua(int size)
{
	int c_floor;
	int c_line;
	int len;
	int shift;
	int start_door;

	c_floor = 0;
	len = -1;
	shift = 2;
	while (c_floor++ < size)
	{
		c_line = 1;
		while (c_line++ <= (c_floor + 2))
			len = len + 1;
		if (c_floor % 2 && c_floor > 1)
			shift++;
		len = shift + len;
	}
	start_door = size - 1;
	if (size % 2)
		start_door++;
	build(((len - shift) * 2) + 3, size, start_door);
}
