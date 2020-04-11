/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 03:25:03 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/01 13:57:39 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*a(int hour)
{
	char *a;

	if (hour >= 12 && hour <= 23)
		a = "P.M.";
	else
		a = "A.M.";
	return (a);
}

int		b(int hour)
{
	int b;

	if (hour % 12 == 0)
		b = 12;
	else
		b = hour % 12;
	return (b);
}

void	ft_takes_place(int hour)
{
	if (hour < 0 || hour > 23)
		return ;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %s AND ", b(hour), a(hour));
	printf("%d.00 %s\n", b(hour + 1), a(hour + 1));
}
