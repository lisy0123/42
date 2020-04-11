/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:47:32 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/04 23:11:30 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_opertor.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int		check(char *op)
{
	if (op[1] != '\0')
		return (9);
	if (op[0] == '+')
		return (0);
	else if (op[0] == '-')
		return (1);
	else if (op[0] == '/')
		return (2);
	else if (op[0] == '%')
		return (3);
	else if (op[0] == '*')
		return (4);
	else
		return (9);
}

int		cul(int a, int b, int c)
{
	int	(*f[5])(int a, int b);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_div;
	f[3] = &ft_mod;
	f[4] = &ft_mul;
	return (f[c](a, b));
}

int		main(int argc, char *argv[])
{
	int opertor;
	int res;

	if (argc != 4)
		return (0);
	opertor = check(argv[2]);
	if (opertor == 9)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else if (opertor == 2 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (opertor == 3 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	res = cul(ft_atoi(argv[1]), ft_atoi(argv[3]), opertor);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
