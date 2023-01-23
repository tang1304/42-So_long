#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# --- COLORS --- #

_NOC	:=	\033[0m
_RED	:=	\033[1;31m
_GREEN	:=	\033[1;32m

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -Wno-deprecated-declarations

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
	@echo "${_GREEN}### ${NOM} created ###${_NOC}\n"

clean:
	rm -f $(OBJ) *~
	rm -f mlx_app
	@echo "${_RED}### Removed MLX object files ###${_NOC}"

fclean:
	rm -f ${NOM}
	@echo "${_RED}### Removed ${NOM} ###${_NOC}"

re: fclean all
