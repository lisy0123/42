/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 06:25:11 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 20:00:29 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*printsquare(int n, char a, char b, char c)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	if (!(str = (char*)malloc(sizeof(char) * n + 2)))
		return (0);
	str[x++] = a;
	if (n > 2)
		while (i++ < n - 2)
			str[x++] = b;
	if (n > 1)
		str[x++] = c;
	str[x++] = '\n';
	str[x] = '\0';
	return (str);
}

char	*rush(int x, int y, char *tab)
{
	int		i;
	char	*t;
	char	*m;
	char	*b;

	i = 0;
	if (!(t = (char *)malloc(sizeof(char) * (y + 1)))
	|| !(m = (char *)malloc(sizeof(char) * (x + 1) * (y + 1)))
	|| !(b = (char *)malloc(sizeof(char) * (y + 1))))
		return (0);
	if (x > 0)
	{
		if (y > 0)
			t = printsquare(x, tab[0], tab[1], tab[2]);
		if (y > 2)
			m = printsquare(x, tab[3], ' ', tab[3]);
		if (y > 1)
			b = printsquare(x, tab[4], tab[1], tab[5]);
	}
	return (c_str(t, m, b, y));
}

char	*c_str(char *t, char *m, char *b, int line)
{
	int		len;
	char	*str;
	int		x;
	int		y;

	x = 0;
	len = ft_strlen(t);
	if (!(str = (char *)malloc(sizeof(char) * line * len + 1)))
		return (0);
	while (*t)
		str[x++] = *t++;
	while (line > 2)
	{
		y = 0;
		while (m[y])
			str[x++] = m[y++];
		line--;
	}
	while (*b)
		str[x++] = *b++;
	str[x] = '\0';
	return (str);
}
