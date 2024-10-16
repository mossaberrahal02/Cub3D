NAME = cub3D

CC = gcc
CFLAGS = #-Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm

SRCS = src/cub3d.c src/hooks.c src/map_parser.c src/raycasting.c \
		src/render_3d.c src/draw_map.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: all

#https://docs.oracle.com/cd/E67482_01/oscar/pdf/4560/OnlineHelp_4560/helpOnPS2keyCodes.html