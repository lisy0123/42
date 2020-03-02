#include "get_next_line.h"

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("your_file_name", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
