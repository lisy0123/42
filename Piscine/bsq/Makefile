# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 16:16:38 by sanlee            #+#    #+#              #
#    Updated: 2019/11/11 22:18:03 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = *.c
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean : 
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
