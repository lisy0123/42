/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:52:10 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 02:46:41 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_opertor(int a, int b, char op);
int		experssion(char **str);
int		mul_expression(char **str);
int		expression(char **str);
int		eval_expr(char *str);

#endif
