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
CFLAGS = $(INCS) -Wall -Wextra -Werror
CFILES = main.c calc.c\
		./texture/map.c ./texture/player.c ./texture/treasure.c\
		./config/read_config.c ./config/process_map.c ./config/check_map.c\
		./key/press_key.c ./key/move_player.c ./key/action.c ./key/key_update.c\
		./end_game/end_game.c ./end_game/free.c
BONUS_CFILES = ./bonus/main.c ./bonus/calc.c\
		./bonus/texture/map.c ./bonus/texture/player.c ./bonus/texture/treasure.c\
		./bonus/config/read_config.c ./bonus/config/process_map.c ./bonus/config/check_map.c\
		./bonus/key/press_key.c ./bonus/key/move_player.c ./bonus/key/action.c ./bonus/key/key_update.c\
		./bonus/end_game/end_game.c ./bonus/end_game/free.c
OBJ = $(CFILES:.c=.o)
BONUS_OBJ = $(BONUS_CFILES:.c=.o)
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
	rm -f $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./gnl fclean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C $(MLX_PASS) clean
re: fclean all
bonus:  $(MLX) $(BONUS_OBJ) $(GNL) $(LIBFT)
	$(CC) $(BONUS_OBJ) -o $(NAME) $(CFLAGS) $(LIBS) $(API)
.PHONY: all clean fclean re bonus

