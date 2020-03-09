/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:21:02 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/09 15:21:21 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int i)
{
	if (i == 1)
		ft_putstr(ERROR1);
	else if (i == 2)
		ft_putstr(ERROR2);
	exit(1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		error(2);
		return (0);
	}
	if ()
	{
	}
	else
		error(1);
	return (1);
}
