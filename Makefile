NAME = so_long
CC = gcc
COMMON_LIBS = -lmlx -Lgnl -lgnl -Llibft -lft
ifeq ($(shell uname), Darwin)
	INCS = -I. -Iminilibx-mac -Ignl -Ilibft
	MLX = ./minilibx-mac/libmlx.dylib
	LIBS = -Lminilibx-mac $(COMMON_LIBS)
	API = -framework OpenGL -framework AppKit
	MLX_PASS = ./minilibx-mac/
else
	INCS = -I. -Iminilibx-linux -Ignl -Ilibft
	MLX = ./minilibx-linux/libmlx.a
	LIBS = -Lminilibx-linux $(COMMON_LIBS)
	API = -lXext -lX11 -lm
	MLX_PASS = ./minilibx-linux/
endif
CFLAGS = $(INCS)
CFILES = main.c end_game.c calc.c\
		handle_texture.c
OBJ = $(CFILES:.c=.o)
GNL = ./gnl/libgnl.a
LIBFT = ./libft/libft.a
HEAD = so_long.h

all: $(NAME)
$(NAME): $(MLX) $(OBJ) $(GNL) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBS) $(API)
$(GNL):
	$(MAKE) -C ./gnl/
$(LIBFT):
	$(MAKE) -C ./libft/
$(MLX):
	git submodule update -i
	$(MAKE) -C $(MLX_PASS)
	cp $(MLX) .
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./gnl fclean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C $(MLX_PASS) clean
re: fclean all
.PHONY: all clean fclean re

