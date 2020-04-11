/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:05:56 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/29 16:27:52 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		error(char *base)
{
	int i;
	int j;

	i = 0;
	if (!base)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	display(int nbr, char *base, unsigned int base_len)
{
	unsigned int n;

	if (nbr < 0)
	{
		ft_putchar('-');
		n = nbr * -1;
	}
	else
		n = nbr;
	if (n >= base_len)
		display(n / base_len, base, base_len);
	ft_putchar(base[n % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int base_len;

	base_len = 2;
	base_len = error(base);
	if (!base_len)
		return ;
	display(nbr, base, base_len);
}
