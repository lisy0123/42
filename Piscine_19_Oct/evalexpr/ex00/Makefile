# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 13:41:09 by sanlee            #+#    #+#              #
#    Updated: 2019/11/10 02:49:37 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
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
