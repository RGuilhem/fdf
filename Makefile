CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = main.c \
	  put_pixel.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = fdf

INCLUDES = -Iincludes/
LIB = libft.a libmlx.a

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -g -fsanitize=address

all: ${NAME}

${LIB}:
	cd libft/ && cp libmlx.a ../
	cd libft/ && make && cp -v libft.a ../

$(NAME): ${LIB} $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -L. -lmlx -lm -lft -framework OpenGL -framework AppKit -o $(NAME) -g -fsanitize=address

re: fclean all

clean:
	cd libft/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}

.PHONY: all re clean fclean
