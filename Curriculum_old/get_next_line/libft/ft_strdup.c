/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:27:46 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/21 17:15:06 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;

	str = ((char *)malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (str)
		return (ft_strcpy(str, s1));
	return (NULL);
}
