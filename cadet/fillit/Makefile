# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 14:18:16 by sanlee            #+#    #+#              #
#    Updated: 2020/03/09 14:22:24 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Werror -Wextra
SRCS = *.c
OBJS = *.o
HEADER = -I. -Ilibft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): 
	@make -C libft
	@$(CC) -c $(SRCS) $(HEADER) -o $(NAME)

clean: 
	@/bin/rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
