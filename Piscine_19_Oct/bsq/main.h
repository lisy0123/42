/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:23:36 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/12 16:54:52 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	int			i;
	int			file;
	int			height;
	int			width;
	int			size;
	int			xpos;
	int			ypos;
	char		point;
	char		ob;
	char		cross;
	char		**tab;
}				t_list;

void			ft_putchar(char c);
void			ft_putstr(char *str, int output);
void			ft_putnbr(int nb);
void			ft_tab(t_list list);
int				ft_atoi(const char *str, t_list *list);
int				ft_open(char *f, t_list list);
int				ft_parameter(t_list list);
void			bsq(int argc, char *argv[]);

#endif
