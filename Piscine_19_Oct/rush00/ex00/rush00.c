/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:14:38 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/27 14:54:56 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fl_line(int x1, int x)
{
	if (x1 == 1 || x1 == x)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	m_line(int x1, int x)
{
	if (x1 == 1 || x1 == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int x1;
	int y1;

	y1 = 1;
	while (y1 <= y)
	{
		x1 = 1;
		while (x1 <= x)
		{
			if (y1 == 1 || y1 == y)
				fl_line(x1, x);
			else
				m_line(x1, x);
			x1++;
		}
		ft_putchar('\n');
		y1++;
	}
}

int	main(int argc, char *argv[])
{
	rush(argv[1][0] - 48, argv[2][0] - 48);
}