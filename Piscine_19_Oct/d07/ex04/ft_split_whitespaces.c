/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:32:30 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/31 19:32:01 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		word(char c, char b)
{
	return (((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
				(c >= 'a' && c <= 'z')) &&
			(b == ' ' || b == '\n' || b == '\t'));
}

int		string(int i, char *str)
{
	return (i > 0 && str[i - 1] != ' '
			&& str[i - 1] != '\n' && str[i - 1] != '\t');
}

int		count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (word(str[i], str[i - 1]) || (str[i] != ' '
					&& str[i] != '\n' && str[i] != '\t' && i == 0))
			count++;
		i++;
	}
	return (count);
}

int		*size(char *str)
{
	int i;
	int c;
	int x;
	int *s;

	c = count(str);
	s = malloc(c * sizeof(int));
	i = 0;
	while (i++ <= c)
		s[i] = 0;
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			s[x]++;
		else if (string(i, str) != '\0')
			x++;
		i++;
	}
	return (s);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		x;
	int		*s;
	char	**w;

	w = malloc((count(str) + 1) * sizeof(char*));
	s = size(str);
	i = 0;
	j = 0;
	x = -1;
	while (str[++x] != '\0')
	{
		if (str[x] != ' ' && str[x] != '\n' && str[x] != '\t')
		{
			if (x == 0 || word(str[x], str[x - 1]))
				w[i] = malloc(s[i] * sizeof(char));
			w[i][j] = str[x];
			w[i][++j] = '\0';
		}
		else if (string(x, str) && ++i)
			j = 0;
	}
	w[count(str)] = 0;
	return (w);
}
