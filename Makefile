NAME = so_long

SOURCES = so_long.c boundaries.c check.c path.c flood.c\
		map.c map_utils.c mlx_input_extra.c mlx_input.c utilities.c

REMOVE = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLBX = -Lminilibx-linux -lmlx_Linux
X11 = -lX11 -lXext
LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Extracting Minilibx..."
	@tar -xzf minilibx-linux.tgz
	@echo "Compiling Minilibx..."
	@cd minilibx-linux/ && make -s
	@cd ../
	@echo "Compiling Libft..."
	@cd libft/ && make -s
	@cd ../
	@echo "Compiling executable..."
	@$(CC) $(CFLAGS) $(SOURCES) $(MLBX) $(X11) -o $(NAME) $(LIBFT)
	@echo "Game compiled successfully!"

clean:
	@echo "Deleting Minilibx data..."
	@test -d "minilibx-linux/" && rm -rf "minilibx-linux/" || echo "No minilibx directory found!"
	@echo "Cleaning Libft folder..."
	@cd libft/ && make clean -s
	@cd ../

fclean: clean
	@test -f $(NAME) && $(REMOVE) $(NAME) && echo "Executable deleted successfully!" || echo "Executable already deleted!"

re: fclean all

.PHONY: all clean fclean re