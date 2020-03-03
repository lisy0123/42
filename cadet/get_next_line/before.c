#include "get_next_line.h"
#include "libft/libft.h"

static int	append(char **c, char **line)
{
	int		len;
	char	*tmp;
	
	len = 0;
	while ((*c)[len] != '\n' && (*c)[len] != '\0')
		len++;
	if ((*c)[len] == '\n')
	{
		*line = ft_strsub(*c, 0, len);
		tmp = ft_strdup(&((*c)[len + 1]));
		free(*c);
		*c = tmp;
		if ((*c)[0] == '\0')
			ft_strdel(c);
	}
	else
	{
		*line = ft_strdup(*c);
		ft_strdel(c);
	}
	return (1);
}

static int	output(char **s, char **line, int a, int fd)
{
	if (a < 0)
		return (-1);
	else if (a == 0 && s[fd] == NULL)
		return (0);
	else
		return (append(&s[fd], line));
}

int				get_next_line(const int fd, char **line)
{
	int			a;
	static char	*c[2147483647];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((a = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[a] = '\0';
		if (c[fd] == NULL)
			c[fd] = ft_strdup(buff);													
		else
		{
			tmp = ft_strjoin(c[fd], buff);
			free(c[fd]);
			c[fd] = tmp;
		}
		if (ft_strchr(c[fd], '\n'))
			break ;
	}
	return (output(c, line, a, fd));
}
