/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 03:04:05 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 07:10:18 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int					ft_strlen(char *str)
{
	int				size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void				ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	n = nb;
	c = n + '0';
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		write(1, &c, 1);
}

int					ft_col(t_char *start)
{
	int				i;

	i = 0;
	while (start->character != '\n' && start->character != '\0')
	{
		i++;
		start = start->next;
	}
	return (i);
}

int					ft_lines(t_char *start)
{
	int				i;
	int				lines;

	i = 0;
	lines = 0;
	while (start->next)
	{
		if (start->character == '\n' || start->character == '\0')
			lines++;
		start = start->next;
	}
	return (lines);
}
