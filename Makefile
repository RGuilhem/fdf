CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 -g
RM = rm -rf

SRC = main.c \
	  quit_program.c \
	  read_lines.c \
	  map_create.c \
	  map_destroy.c \
      map_project.c \
	  wf_create.c \
	  wf_destroy.c \
	  wf_copy.c \
	  wf_scale.c \
	  wf_transform.c \
	  wf_translate.c \
	  vec_add.c \
	  vec_create.c \
	  vec_destroy.c \
	  vec_multiply.c \
	  matrix_create.c \
	  matrix_destroy.c \
	  gui_create.c \
	  gui_destroy.c \
	  gui_draw_all.c \
	  gui_draw_map.c \
	  gui_run.c \
	  draw_line.c \
	  put_pixel.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = fdf

INCLUDES = -Iincludes/
LIB = libft.a libmlx.a

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${LIB}:
	cd mlx_mac && make && cp -v libmlx.a ../
	cd libft/ && make && cp -v libft.a ../

$(NAME): ${LIB} $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -L. -lmlx -lm -lft -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	cd libft/ && make clean
	cd mlx_mac/ && make clean
	${RM} ${OBJ}

fclean: clean
	cd libft/ && make fclean
	${RM} ${NAME}
	${RM} ${LIB}

.PHONY: all re clean fclean
