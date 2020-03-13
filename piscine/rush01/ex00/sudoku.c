/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:25:36 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/03 21:07:09 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "base.h"

int		check(int *a[], int x, int y, int n)
{
	int		i;
	int		j;
	int		l_x;
	int		l_y;

	i = -1;
	while (++i < 9)
		if (a[i][y] == n)
			return (0);
	i = -1;
	while (++i < 9)
		if (a[x][i] == n)
			return (0);
	l_x = (x / 3 + 1) * 3 - 1;
	l_y = (y / 3 + 1) * 3 - 1;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (a[l_x - i][l_y - j] == n)
				return (0);
	}
	return (1);
}

int		find(int *a[], int x, int y, int num)
{
	int		n;

	n = num;
	if (x >= 8 && y > 8)
		return (1);
	if (y > 8 && ++x)
		y = 0;
	if (a[x][y] != 0)
		return (find(a, x, y + 1, num));
	while ((n <= 9 && num == 1) || (n >= 1 && num == 9))
	{
		if (check(a, x, y, n))
		{
			a[x][y] = n;
			if ((x == 8 && y == 8) || find(a, x, y + 1, num))
				return (1);
		}
		if (num == 9)
			--n;
		else
			++n;
	}
	return (a[x][y] = 0);
}

int		input_check(char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if (!(argv[i][j] >= '1' && argv[i][j] <= '9'))
				if (argv[i][j] != '.')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		**a;
	int		**b;
	int		i;

	a = malloc(sizeof(int*) * 9);
	b = malloc(sizeof(int*) * 9);
	i = -1;
	while (i++ < 9)
	{
		a[i] = malloc(sizeof(int) * 9);
		b[i] = malloc(sizeof(int) * 9);
	}
	if (argc != 10 || input_check(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	setting(a, argv);
	find(a, 0, 0, 1);
	setting(b, argv);
	find(b, 0, 0, 9);
	finish(a, b);
	free(a);
	free(b);
	return (0);
}
