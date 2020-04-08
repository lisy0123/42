/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opertor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:57:18 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/05 14:19:11 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERTOR_H
# define FT_OPERTOR_H

int				ft_atoi(char *str);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_mul(int a, int b);
int				ft_usage(int a, int b);

typedef struct	s_opp
{
	char		*op;
	int			(*function)(int, int);
}				t_opp;

#endif
