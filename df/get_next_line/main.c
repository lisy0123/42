#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		i;

	ac = 0;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	i = get_next_line(fd1, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd2, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd1, &line);
	printf("%d %s\n", i, line);	
	i = get_next_line(fd2, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd1, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd2, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd1, &line);
	printf("%d %s\n", i, line);
	i = get_next_line(fd2, &line);
	printf("%d %s\n", i, line);
	return (0);
}
