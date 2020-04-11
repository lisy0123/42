/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:25:36 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/30 14:53:17 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		order(int argc, char **arv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < (argc - 1))
	{
		j = 0;
		while (arv[i][j] == arv[i + 1][j])
			j++;
		if (arv[i][j] > arv[i + 1][j])
		{
			temp = arv[i];
			arv[i] = arv[i + 1];
			arv[i + 1] = temp;
			i = 0;
		}
		i++;
	}
	return (0);
}

int		printing(int argc, char **arv)
{
	int i;
	int j;

	if (argc > 0)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (arv[i][j] != '\0')
			{
				ft_putchar(arv[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}

int		main(int argc, char *arv[])
{
	order(argc, arv);
	printing(argc, arv);
	return (0);
}
