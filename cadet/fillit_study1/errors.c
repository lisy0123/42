/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:00:55 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/09 14:30:18 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** used to print usage or error and exit the app.
*/

void			dp_error(int c)
{
	if (c == 1)
		ft_putstr_fd(ERR1, 1);
	else if (c == 2)
		ft_putstr_fd(ERR2, 1);
	exit(1);
}
