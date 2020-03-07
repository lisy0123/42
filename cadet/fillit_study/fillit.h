#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_tetri
{
	char			**minos;
	char			letter;
	int				height;
	int				width;
}					t_tetri;

typedef struct		s_size
{
	int				height;
	int				width;
}					t_size;

t_list				*ft_read_fd(int fd);

int					ft_bufcheck(char *buffer, int length);

char				**ft_new_tab(int size);
char				**ft_solve(t_list *tetriminos);

void				ft_display(char **map);
void				ft_throw_error();

int		ft_sqrt(int nbr);
int	ft_lst_count(t_list *lst);

#endif
