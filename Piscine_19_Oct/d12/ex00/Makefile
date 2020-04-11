# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 12:48:40 by sanlee            #+#    #+#              #
#    Updated: 2019/11/07 19:24:20 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
FLAGS = -Wall -Wextra -Werror
SRCS = display_file.c
OBJS = display_file.o

all : $(NAME)

$(NAME) : 
	gcc -c $(SRCS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
