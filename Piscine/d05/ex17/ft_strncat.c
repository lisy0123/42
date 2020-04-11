/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:00:49 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/29 00:42:15 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	i = 0;
	while ((src[i] != '\0') && (i < nb))
	{
		dest[count + i] = src[i];
		i++;
	}
	dest[count + i] = '\0';
	return (dest);
}
