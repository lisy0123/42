/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 06:19:32 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 19:58:56 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**ft_tab(void)
{
	char **tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 5 * 5)))
		return (0);
	tab[COLLE00] = "o-o|oo";
	tab[COLLE01] = "/*\\*\\/";
	tab[COLLE02] = "ABABCC";
	tab[COLLE03] = "ABCBAC";
	tab[COLLE04] = "ABCBCA";
	return (tab);
}

char	**ft_call(int col, int line)
{
	char	**str;
	char	**c;
	int		i;

	i = 0;
	c = ft_tab();
	if (!(str = (char **)malloc(sizeof(char *) * col * (line + 1))))
		return (0);
	while (i < 5)
	{
		str[i] = rush(col, line, c[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

int		ft_listcmp(char *str, t_char *list)
{
	while (list->next && *str)
	{
		if (list->character != *str++)
			return (0);
		list = list->next;
	}
	return (1);
}

int		*ft_compare(char **compare, t_char *start)
{
	int		*i;
	int		nbr;

	nbr = 0;
	if (!(i = (int *)malloc(sizeof(int) * 5)))
		return (0);
	while (nbr < 5)
	{
		i[nbr] = ft_listcmp(compare[nbr], start);
		nbr++;
	}
	return (i);
}
