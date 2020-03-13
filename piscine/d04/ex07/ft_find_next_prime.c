/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:43:20 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/26 21:19:47 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 1)
	{
		return (2);
	}
	else
	{
		i = 2;
		while (i < (nb / 2))
		{
			if (nb % i == 0)
			{
				return (ft_find_next_prime(nb + 1));
			}
			i++;
		}
		return (nb);
	}
}
