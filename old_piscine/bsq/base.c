/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:23:50 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/12 16:53:22 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int output)
{
	while (*str)
	{
			write(output, str, 1);
			str++;
		}
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_tab(t_list list)
{
	int i;
	int j;

	i = 0;
	while (i < list->height)
	{
		j = 0;
		while (j < list->width)
		{
			ft_putchar(list->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_atoi(const char *str, t_list *list)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	list->point = str[i];
	list->ob = str[i + 1];
	list->cross = str[i + 2];
	return (res);
}
