/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:10:17 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/28 16:33:28 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			res = str + i;
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (res);
				j++;
			}
			res = 0;
		}
		i++;
	}
	return (0);
}
