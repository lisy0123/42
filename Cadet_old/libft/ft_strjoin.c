/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:04:59 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 14:44:04 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	if (s1 != NULL && s2 != NULL && (new = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		i = 0;
		while (*s1)
		{
			new[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			new[i] = *s2;
			i++;
			s2++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
