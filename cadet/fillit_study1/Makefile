NAME=fillit
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=*.c
OBJS=*.o

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	
	(CC) $(CFLAGS) -c $(SRCS) -I. -Ilibft/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
