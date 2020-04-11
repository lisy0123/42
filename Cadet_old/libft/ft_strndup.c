/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:22:19 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/22 00:31:41 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (str)
	{
		ft_strncpy(str, s1, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
