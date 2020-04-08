/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:51:56 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/24 15:54:45 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*des;
	unsigned char	*sc;

	if (!n || dst == src)
		return (dst);
	i = 0;
	des = (unsigned char *)dst;
	sc = (unsigned char *)src;
	while (i < n)
	{
		des[i] = sc[i];
		i++;
	}
	return (dst);
}
