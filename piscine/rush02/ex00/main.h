/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 03:03:58 by sanlee            #+#    #+#             */
/*   Updated: 2019/11/10 19:59:20 by sanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define COLLE00 0
# define COLLE01 1
# define COLLE02 2
# define COLLE03 3
# define COLLE04 4

typedef struct		s_char
{
	char			character;
	struct s_char	*next;
}					t_char;

t_char				*ft_create_elem(void);
int					ft_col(t_char *start);
int					ft_lines(t_char *start);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_list(t_char *list_start);
char				*printsquare(int n, char a, char b, char c);
char				*rush(int x, int y, char *tab);
int					ft_strlen(char *str);
char				*c_str(char *t, char *m, char *b, int line);
char				*rush(int x, int y, char *tab);
char				*printsquare(int n, char a, char b, char c);
char				**ft_tab(void);
char				**ft_call(int col, int lines);
int					*ft_compare(char **compare, t_char *start);
int					ft_listcmp(char *str, t_char *list);
void				ft_results(int *res, int col, int line);

#endif
