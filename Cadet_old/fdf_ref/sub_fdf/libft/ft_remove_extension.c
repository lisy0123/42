/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 00:32:47 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/12 00:32:48 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove the extension (type) of a filename, returning its basename.
*/

char	*ft_remove_extension(char *filename)
{
	char	*base_name;
	char	*dot;
	char	*sep;

	if (!filename)
		return (NULL);
	if (!(base_name = (char *)malloc(sizeof(char) * ft_strlen(filename) + 1)))
		return (NULL);
	ft_strcpy(base_name, filename);
	if ((dot = ft_strrchr(base_name, '.')))
	{
		if ((sep = ft_strrchr(base_name, '/')))
			(sep < dot) ? *dot = '\0' : *dot;
		else
			*dot = '\0';
	}
	return (base_name);
}
