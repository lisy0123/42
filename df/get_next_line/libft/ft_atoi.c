/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:49:43 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 23:52:34 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	n;
	int		s;

	while (ft_space(*str))
		str++;
	s = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (ft_isdigit(*str))
	{
		n += *str - '0';
		if (ft_isdigit(*(++str)))
			n *= 10;
		if (n < 0)
		{
			if (s < 0)
				return (0);
			else
				return (-1);
		}
	}
	return ((n * (long)s));
}
