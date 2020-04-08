# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 16:20:08 by sanlee            #+#    #+#              #
#    Updated: 2019/11/07 21:39:53 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
FLAGS = -Wall -Wextra -Werror
SRCS = cat.c
OBJS = cat.o

all : $(NAME)

$(NAME) : 
	gcc -c $(SRCS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
