/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:20:17 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/26 14:17:49 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_interative_power(int nb, int power)
{
	int i;
	int x;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		i = 1;
		x = 1;
		while (power >= 1)
		{
			x = x * nb;
			power--;
		}
		return (x);
	}
}
