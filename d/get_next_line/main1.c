#include "get_next_line.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	char	*line = 0;
	int 	ret;
	int		fd;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		printf("%d  %s\n", ret, line);
	return (0);
}
