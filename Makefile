NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = include
LIBFTDIR = libs/libft
GNLDIR = libs/get_next_line
MLXDIR = libs/minilibx-linux

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/parsing/arguments.c \
	   $(SRCDIR)/parsing/validation.c \
	   $(SRCDIR)/parsing/element_parser.c \
	   $(SRCDIR)/parsing/file_reader.c \
	   $(SRCDIR)/parsing/map_parser.c \
	   $(SRCDIR)/core/init.c \
	   $(SRCDIR)/game/input.c \
	   $(SRCDIR)/game/movement.c \
	   $(SRCDIR)/game/player.c \
	   $(SRCDIR)/rendering/drawing.c \
	   $(SRCDIR)/rendering/minimap.c \
	   $(SRCDIR)/rendering/raycasting.c \
	   $(SRCDIR)/rendering/textures.c \
	   $(SRCDIR)/utils/cleanup.c \
	   $(SRCDIR)/utils/error.c \
	   $(SRCDIR)/utils/libft_utils.c \
	   $(SRCDIR)/utils/math_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
GNL = $(GNLDIR)/get_next_line.a
MLX = $(MLXDIR)/libmlx.a

MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft $(GNL) $(MLXFLAGS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(GNL):
	make -C $(GNLDIR)

$(MLX):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "MinilibX not found. Run 'make get' first."; \
		exit 1; \
	fi
	make -C $(MLXDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(GNLDIR) -I$(MLXDIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(GNLDIR) clean
	@if [ -d "$(MLXDIR)" ]; then make -C $(MLXDIR) clean; fi

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(GNLDIR) fclean
	@if [ -d "$(MLXDIR)" ]; then rm -rf $(MLXDIR); fi

re: fclean all

get:
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXDIR); \
		echo "MinilibX cloned to libs/"; \
	else \
		echo "MinilibX already exists in libs/"; \
	fi

norm:
	norminette $(SRCDIR) $(INCDIR)

.PHONY: all clean fclean re get norm