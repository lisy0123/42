/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:47:39 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/29 01:15:03 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
