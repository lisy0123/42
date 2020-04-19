/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:01:23 by sanlee            #+#    #+#             */
/*   Updated: 2020/04/19 23:54:15 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		j;

	if (s == NULL || c == 0)
		return (NULL);
	len = ft_count(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	str[len] = 0;
	i = 0;
	while (s[i])
		i++;
	while (--len >= 0)
	{
		while (i > 0 && s[i - 1] == c)
			i--;
		j = i;
		while (j > 0 && s[j - 1] != c)
			j--;
		str[len] = ft_strndup(s + j, i - j);
		i = j;
	}
	return (str);
}
