/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:59:31 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/28 21:15:18 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		space;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		space = 1;
		if (i == 0)
			c = ';';
		else
			c = str[i - 1];
		if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
			space = 0;
		if (c >= 48 && c <= 57)
			space = 0;
		if (space == 1 && str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		if (space == 0 && str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
