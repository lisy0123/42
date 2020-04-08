/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:26:55 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 21:11:54 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int	i;
	int	j;

	if (str2[0] == '\0')
		return ((char *)str1);
	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)(str1 + i));
		}
		i++;
	}
	return (NULL);
}
