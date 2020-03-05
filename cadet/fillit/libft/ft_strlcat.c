/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:30:14 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/20 12:44:16 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[k])
		k++;
	if (len <= i)
		k += len;
	else
		k += i;
	while (len > 0 && i + j < len - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (len != 0)
		dst[i + j] = '\0';
	return (k);
}
