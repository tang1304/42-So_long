# --- VARIABLES --- #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
BONUS_DIR = ./bonus/
SRCS = so_long.c \
		image.c \
		key_hook.c \
		map.c \
		map2.c \
		path_check.c \
		move.c \
		utils.c
SRCS_BONUS = so_long_bonus.c \
			map_bonus.c \
			map2_bonus.c \
			path_check_bonus.c \
			image_bonus.c \
			image2_bonus.c \
			key_hook_bonus.c \
			utils_bonus.c \
			move_anim_bonus.c \
			anim_enemy_bonus.c \
			anim_player_bonus.c
OBJ_DIR = objs/
OBJ = ${SRCS:%.c=${OBJ_DIR}%.o}
OBJ_BONUS = ${SRCS_BONUS:%.c=${OBJ_DIR}%.o}
NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -f
HEADER = so_long.h
HEADER_BONUS = ${BONUS_DIR}so_long_bonus.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/

# --- OS SELECTION --- #

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_A	=	${MLX_DIR}libmlx.a
		MLX_DIR	=	mlx/mlx_linux/
		MLX_FLAGS = -lm -L/usr/lib -lXext -lX11
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

${NAME} :	${OBJ} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${NAME_BONUS} :	${OBJ_BONUS} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME_BONUS}
		@echo "${_GREEN}### ${NAME_BONUS} created ###${_NOC}\n"

${OBJ}: ${OBJ_DIR}%.o :	%.c ${HEADER} ${LIBFT} ${MLX_A}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $< -o $@

${OBJ_BONUS}: ${OBJ_DIR}%.o :	${BONUS_DIR}%.c ${HEADER_BONUS} ${LIBFT} ${MLX_A}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $< -o $@

${LIBFT}: FORCE
		${MAKE} -sC ${LIBFT_DIR}

${MLX_A}: FORCE
		@${MAKE} -sC ${MLX_DIR}

FORCE:

all :	${NAME}

bonus :	${NAME_BONUS}

clean :
		@${MAKE} clean -sC ${LIBFT_DIR}
		@${MAKE} clean -sC ${MLX_DIR}
		rm -rf objs/
		@echo "${_RED}### Removed So_long object files ###${_NOC}"

fclean :	clean
		@${MAKE} fclean -sC ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} and/or ${NAME_BONUS} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE bonus
