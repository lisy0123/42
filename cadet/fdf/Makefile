NAME = fdf
CC = gcc -Wall -Werror -Wextra
SRCS = ./source/*.c
OJCS = *.o
HEADER = -I./include/.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C ./libs/libft/
	@$(CC) -c $(SRCS) $(HEADER)
	@$(CC) -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@make -C ./libs/libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libs/libft/ fclean

re: fclean all
