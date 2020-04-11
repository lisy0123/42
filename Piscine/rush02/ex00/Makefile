# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 03:01:25 by sanlee            #+#    #+#              #
#    Updated: 2019/11/10 06:20:41 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRCS = *.c
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : 
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
