/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:18:43 by sanlee            #+#    #+#             */
/*   Updated: 2019/10/29 23:16:09 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		error(char *str, char *base)
{
	int i;
	int j;
	int c;

	c = 0;
	while (str[c] != '\0'
			&& (str[c] == ' ' || str[c] == '\t' || str[c] == '\r'
				|| str[c] == '\n' || str[c] == '\v' || str[c] == '\f'))
		c++;
	i = c;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] && (str[i] != base[j]
					|| (str[i] == '-' || str[i] == '+')))
			++j;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	a;
	int	i;
	int	res;
	int	neg;
	int	b_len;

	if (!(b_len = base_len(base)) || !error(str, base))
		return (0);
	a = 0;
	while (str[a] != '\0'
			&& (str[a] == ' ' || str[a] == '\t' || str[a] == '\r'
				|| str[a] == '\n' || str[a] == '\v' || str[a] == '\f'))
		a++;
	i = a - 1;
	res = 0;
	neg = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == a)
				|| (str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			neg = -1;
		else if (str[i] != '+')
			res = (res * b_len) + (num(str[i], base));
	}
	return (res * neg);
}
