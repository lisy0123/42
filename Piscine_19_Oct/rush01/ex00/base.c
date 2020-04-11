/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:31:04 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/03 21:07:46 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	setting(int *a[], char *argv[])
{
	int		x;
	int		y;

	x = 1;
	while (x <= 9)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (argv[x][y] >= '1' && argv[x][y] <= '9')
				a[x - 1][y] = argv[x][y] - 48;
			else
				a[x - 1][y] = 0;
			++y;
		}
		++x;
	}
}

void	display(int *a[])
{
	int		i;
	int		j;
	int		v;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			v = a[i][j] + 48;
			write(1, &v, 1);
			if (j + 1 < 9)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int		fin_check(int **a, int **b)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (a[i][j] == 0 || (a[i][j] != b[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	finish(int *a[], int *b[])
{
	if (fin_check(a, b))
		display(a);
	else
	{
		write(1, "Error\n", 6);
	}
}
