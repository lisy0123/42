/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:46:15 by sanlee            #+#    #+#             */
/*   Updated: 2020/02/27 20:02:54 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static char		*c[2147483647];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			a;
	int				end;

    // error -1
	if (fd < 0 || !line || (!c[fd] && !(c[fd] = ft_strnew(1))))
		return (-1);
	while (!(ft_strchr(c[fd], '\n')) && (a = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[a] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tmp);
	}
    // read -1 0
	if (a == -1 || !*(tmp = c[fd]))
		return ((a == -1) ? -1 : 0);
	if ((end = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, (size_t)(ft_strchr(c[fd], '\n') - c[fd]));
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + end),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + end)));
	ft_strdel(&tmp);
    // 1, 0
	return (!(!c[fd] && !ft_strlen(*line)));
}
