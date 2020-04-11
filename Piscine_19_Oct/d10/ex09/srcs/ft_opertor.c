/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opertor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:55:31 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/04 22:44:46 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_div(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

int		ft_mod(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}
