/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:48:27 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/31 00:10:13 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *a;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	a = (int *)malloc(sizeof(*a) * (max - min));
	while (min < max)
	{
		a[i] = min;
		i++;
		min++;
	}
	*range = a;
	return (i);
}
