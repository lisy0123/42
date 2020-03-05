# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 08:13:24 by sanlee            #+#    #+#              #
#    Updated: 2020/02/22 00:19:15 by sanlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJS = *.o
HEADER = .
CC = gcc -Wall -Wextra -Werror 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) -I $(HEADER) -c $(SRCS)
	@ar -rscv $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
