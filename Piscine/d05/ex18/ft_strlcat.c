/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:14:20 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/29 00:38:10 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int count;
	unsigned int res;

	count = 0;
	while (dest[count] != '\0')
		++count;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= count)
		res = res + size;
	else
		res = res + count;
	i = 0;
	while ((src[i] != '\0') && (count + 1 < size))
	{
		dest[count] = src[i];
		i++;
		count++;
	}
	dest[count] = '\0';
	return (res);
}
