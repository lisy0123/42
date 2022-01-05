#include <stdio.h>

void	sastantua(int size);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error");
		return(0);
	}
	sastantua((argv[1][0]-48));
	return(0);
}
