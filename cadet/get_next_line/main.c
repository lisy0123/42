/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:13:12 by sanlee            #+#    #+#             */
/*   Updated: 2020/03/01 16:45:19 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int   main(int ac, char **av)
{
	char  *line;
	int   fd1;
	int   fd2;
	
	ac = 0;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	return (0);
}
