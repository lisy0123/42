/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:36:13 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/25 14:02:09 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_combn(int n)
{
	int a;
	int b;

	a = 0;
	while (a <= 8)
	{
		b = 0;
		while (b <= 9)
		{
			if (a + b != n)
			{
				ft_putchar(a + 48);
				ft_putchar(b + 48);
				if (a != 8 || b != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			b++;
		}
		a++;
	}
}
