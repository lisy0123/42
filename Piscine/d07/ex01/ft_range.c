/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:56:40 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/30 22:00:59 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *res;

	if (min >= max)
		return (NULL);
	i = 0;
	res = (int *)malloc(sizeof(*res) * (max - min));
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	return (res);
}
