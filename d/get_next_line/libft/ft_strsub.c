/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:48:46 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 23:12:14 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((new = (char *)malloc(sizeof(char) * (len + 1))))
	{
		i = 0;
		while (i < len)
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
