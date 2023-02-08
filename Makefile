# --- VARIABLES --- #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = so_long.c \
		map.c \
		map2.c \
		image.c \
		walls.c \
		colors.c \
		key_hook.c \
		utils.c \
		move.c \
		animation.c
OBJ = ${SRCS:.c=.o}
NAME = so_long
RM = rm -f
HEADERS = so_long.h
LIBFT = libft/libft.a
LIBFT_DIR = -C ./libft/

# --- OS SELECTION --- #

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_A	=	${MLX_DIR}libmlx.a
		MLX_DIR	=	mlx/mlx_linux/
		MLX_FLAGS = -lm -L/usr/lib -lXext -lX11 # -lz
	endif
	ifeq ($(UNAME_S),Darwin)
		MLX_A	=	${MLX_DIR}libmlx.a
		MLX_DIR	=	mlx/mlx_MAC/
		MLX_FLAGS = -Lmlx/mlx_MAC -lmlx -framework OpenGL -framework AppKit
	endif

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# --- RULES --- #

%.o :	%.c ${HEADERS} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $<

${NAME} :	${OBJ} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${LIBFT}: FORCE
		@${MAKE} ${LIBFT_DIR}

${MLX_A}: FORCE
		@${MAKE} -C ${MLX_DIR}

FORCE:

all :	${NAME}

clean :
		@${MAKE} clean ${LIBFT_DIR}
		@${MAKE} clean -C ${MLX_DIR}
		${RM} ${OBJ}
		@echo "${_RED}### Removed So_long object files ###${_NOC}"

fclean :	clean
		@${MAKE} fclean ${LIBFT_DIR}
#		@${MAKE} fclean -C ${MLX_DIR}
		${RM} ${NAME}
		@echo "${_RED}### Removed ${NAME} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE
