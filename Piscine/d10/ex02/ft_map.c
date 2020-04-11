/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:05:20 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/04 16:11:02 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *a;

	i = 0;
	a = malloc(sizeof(int) * length);
	while (i < length)
	{
		a[i] = (*f)(tab[i]);
		i++;
	}
	return (a);
}
