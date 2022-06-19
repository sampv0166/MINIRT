SRCS  = main.c \
		parser/parser.c \
		parser/parse_ambient_lighting.c \
		parser/parse_camera.c \
		parser/parse_cylinder.c \
		parser/parse_light.c \
		parser/parse_plane.c \
		parser/parse_sphere.c \
		utils/utils.c \
		error/error.c \
		free/free_scene_data.c \
		get_next_line.c \
		get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

OS = $(shell uname)

LIBFT = libs/libft/libft.a

LIBFT_PATH = libs/libft

ifeq ($(OS), Linux)
	MLX_FLAGS = -Llibs/mlx_linux -lmlx -Ilibs/mlx_linux -lXext -lX11 -lm -lz
	MLX_PATH = libs/mlx_linux
else
	MLX_FLAGS = -Llibs/mlx_mac -lmlx -Ilibs/mlx_mac -framework OpenGL -framework AppKit
	MLX_PATH = libs/mlx_mac
endif

NAME = miniRT

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) fclean -C $(LIBFT_PATH)

re : fclean all



