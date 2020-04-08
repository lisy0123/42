/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:41:00 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/26 23:38:56 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_mod(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}

int	ft_check(int a, int *b)
{
	int i;

	i = 0;
	while (i < a)
	{
		if (b[i] == b[a])
			return (0);
		if (ft_mod(b[i], b[a]) == ft_mod(i, a))
			return (0);
		i++;
	}
	return (1);
}

int	ft_back(int a, int *b, int *count)
{
	int i;

	i = 0;
	while (i < 8)
	{
		b[a] = i;
		if (ft_check(a, b))
		{
			if (a == 7)
				(*count)++;
			else
				ft_back(a + 1, b, count);
		}
		i++;
	}
}

int	ft_eight_queens_puzzle(void)
{
	int b[8];
	int count;

	count = 0;
	ft_back(0, b, &count);
	return (count);
}
