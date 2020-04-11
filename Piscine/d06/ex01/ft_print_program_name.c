/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:57:56 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/30 02:30:18 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int a;

	a = 0;
	if (argc > 0)
	{
		while (argv[0][a] != '\0')
		{
			ft_putchar(argv[0][a]);
			a++;
		}
		ft_putchar('\n');
	}
	return (0);
}
