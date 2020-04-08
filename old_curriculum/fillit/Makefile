# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 19:11:38 by sanlee            #+#    #+#              #
#    Updated: 2020/03/09 20:47:01 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Werror -Wextra
SRCS = *.c
OBJS = *.o ./libft/*.o
HEADER = .
LIB = ./libft/*.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	@make -C ./libft
	@$(CC) -c $(SRCS) -I$(HEADER) 
	@$(CC) -o $(NAME) $(OBJS)

clean: 
	@/bin/rm -f $(OBJS)
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
