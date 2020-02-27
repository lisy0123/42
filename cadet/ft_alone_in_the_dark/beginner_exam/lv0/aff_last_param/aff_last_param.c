#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac >= 2)
		write(1, av[ac - 1], ft_strlen(av[ac - 1]));
	write(1, "\n", 1);
	return (0);
}
