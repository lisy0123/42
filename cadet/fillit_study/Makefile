NAME=fillit

FLAG=-Wall -Wextra -Werror

HDR=-I ./

SRC=checker.c \
	displayer.c \
	main.c \
	reader.c \
	solver.c \

OBJ=$(SRC:.c=.o)

LIB=./libft/libft.a

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAG) $(OBJ) $(HDR) $(LIB) -o $(NAME)

%.o:%.c
	gcc $(FLAG) $(HDR) -c $< -o $@

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
