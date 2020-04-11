/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:23:43 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/12 16:54:21 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    bsq(int argc, char *argv[])
{
        t_list  list;

        while (*++argv)
        {
                if (open(*argv, &list))
                        break ;
                if (ft_parameter(&list))
                        return (0);
                list->tab = malloc(sizeof(list->tab*) * list->height);
                while ()
                reading();
        }
}

int		main(int argc, char *argv[])
{
	int		i;
	int		r;
	char	*buf;
	char	*buffer;

	if (argc < 2)
	{
		i = 0;
		buffer = malloc(sizeof(char*));
		whiel (r = read(0, &buf, 1))
		{
			buffer[i] = buf;
			i++;
		}
		ft_putstr(buffer, 1);
	}
	else
	{
		bdq(argc, argv);
	}
	return (0);
}
