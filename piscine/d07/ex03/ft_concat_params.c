/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 00:09:22 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/31 01:30:08 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		argv_len(int argc, char **argv)
{
	int i;
	int j;
	int argv_len;

	i = 1;
	argv_len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			argv_len++;
		}
		i++;
	}
	return (argv_len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*a;

	a = (char *)malloc(sizeof(*a) * (argv_len(argc, argv) - 1));
	i = 1;
	k = 0;
	if (argc > 0)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				a[k++] = argv[i][j];
				j++;
			}
			a[k++] = '\n';
			i++;
		}
	}
	a[k - 1] = '\0';
	return (a);
}
