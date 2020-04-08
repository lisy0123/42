/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:47:48 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 02:48:03 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		sub_expression(char **str)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	if ((*str)[0] == '-' || (*str)[0] == '+')
	{
		if ((*str)[0] == '-')
			sign = -1;
		(*str)++;
	}
	if ((*str)[0] == '(')
	{
		(*str)++;
		n = expression(str);
		if ((*str)[0] == ')')
			(*str)++;
		return (n * sign);
	}
	while ((*str)[0] >= '0' && (*str)[0] <= '9')
	{
		n = n * 10 + (*str)[0] - '0';
		(*str)++;
	}
	return (n * sign);
}

int		mul_expression(char **str)
{
	int		a;
	int		b;
	char	op;

	a = sub_expression(str);
	while ((*str[0] == '/' || (*str)[0] == '%' || (*str)[0] == '*'))
	{
		op = (*str)[0];
		(*str)++;
		b = sub_expression(str);
		a = ft_opertor(a, b, op);
	}
	return (a);
}

int		expression(char **str)
{
	int		a;
	int		b;
	char	op;

	a = sub_expression(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		op = (*str)[0];
		(*str)++;
		if (op == '+' || op == '-')
			b = mul_expression(str);
		else
			b = sub_expression(str);
		a = ft_opertor(a, b, op);
	}
	return (a);
}

int		eval_expr(char *str)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] != ' ')
		{
			c[j] = str[i];
			j++;
		}
		i++;
	}
	c[j] = '\0';
	if (c[0] == '\0')
		return (0);
	return (expression(&c));
}
