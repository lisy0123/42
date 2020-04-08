/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:05:12 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/07 22:47:29 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	in(void)
{
	char	c;

	while (read(0, &c, 1) != 0)
		write(1, &c, 1);
}

int		put(int file, char *filename)
{
	if (file < 0)
	{
		write(2, "cat: ", 5);
		write(2, filename, ft_strlen(filename));
		if (errno == 21)
		{
			write(2, ": Is a directory\n", 17);
			return (1);
		}
		else
		{
			write(2, ": No such file or directory\n", 28);
			return (1);
		}
	}
	return (0);
}

void	display(int argc, char *argv[])
{
	int		file;
	int		i;
	char	buffer;
	size_t	bytes;
	char	*filename;

	i = 0;
	while (++i < argc)
	{
		filename = argv[i];
		file = open(filename, O_RDWR);
		if (put(file, filename))
			break ;
		while ((bytes = read(file, &buffer, 1)))
			write(1, &buffer, bytes);
		close(file);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		in();
	else
		display(argc, argv);
	return (0);
}
