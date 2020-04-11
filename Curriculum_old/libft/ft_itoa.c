/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:48:36 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 23:49:40 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numdigit(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else
		str[0] = '0';
	while (n != 0)
	{
		len--;
		if (n < 0)
			str[len] = (n % 10) * -1 + '0';
		else
			str[len] = (n % 10) * 1 + '0';
		n /= 10;
	}
	return (str);
}
