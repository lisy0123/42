/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:18:55 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/12 17:05:59 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_open(char *f, t_list list)
{
	list->file = open(f, O_RDONLY);
	if (list->file == -1)
		reutrn (1);
	return (0);
}

int		ft_parameter(t_list list)
{
	int		j;
	int		r;
	char	*h;
	char	buf[4];
	
	j = 0;
	file->i = 0;
	file->width = 0;
	h = malloc(sizeof(char*));
	while ((r = read(list->file, &buf, 1)))
	{
		if (file->i == 0)
			h[j++] = buf;
		if (file->i == 1 || *buf != '\n')
			file->width++;
		if (file->i >=2)
			break ;
		if (*buf == '\n')
			file->i++;
	}
	return (0);
}

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
