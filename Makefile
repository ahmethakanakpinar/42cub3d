NAME = cub3D

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
	   $(SRCDIR)/parsing/file_validator.c \
	   $(SRCDIR)/parsing/map_validation.c \
	   $(SRCDIR)/parsing/map_walls.c \
	   $(SRCDIR)/parsing/map_parser.c \
	   $(SRCDIR)/parsing/map_counter.c \
	   $(SRCDIR)/parsing/map_utils.c \
	   $(SRCDIR)/parsing/flood_fill.c \
	   $(SRCDIR)/parsing/element_parser.c \
	   $(SRCDIR)/parsing/color_parser.c \
	   $(SRCDIR)/parsing/texture_parser.c \
	   $(SRCDIR)/core/init.c \
	   $(SRCDIR)/core/init_game.c \
	   $(SRCDIR)/core/vector.c \
	   $(SRCDIR)/game/input.c \
	   $(SRCDIR)/game/movement.c \
	   $(SRCDIR)/game/player.c \
	   $(SRCDIR)/rendering/drawing.c \
	   $(SRCDIR)/rendering/raycasting.c \
	   $(SRCDIR)/rendering/textures.c \
	   $(SRCDIR)/rendering/texture_animation.c \
	   $(SRCDIR)/rendering/texture_utils.c \
	   $(SRCDIR)/utils/cleanup.c \
	   $(SRCDIR)/utils/error.c \
	   $(SRCDIR)/utils/libft_utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
GNL = $(GNLDIR)/get_next_line.a
MLX = $(MLXDIR)/libmlx.a

MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft $(GNL) $(MLXFLAGS)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(GNL):
	@make -C $(GNLDIR)

$(MLX):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "MinilibX not found. Run 'make get' first."; \
		exit 1; \
	fi
	@make -C $(MLXDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(GNLDIR) -I$(MLXDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean
	@make -C $(GNLDIR) clean
	@if [ -d "$(MLXDIR)" ]; then make -C $(MLXDIR) clean; fi

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(GNLDIR) fclean
	@if [ -d "$(MLXDIR)" ]; then make -C $(MLXDIR) clean; fi
	@rm -rf $(MLXDIR)

re: fclean get all

get:
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXDIR); \
		echo "MinilibX cloned successfully."; \
	else \
		echo "MinilibX already exists."; \
	fi

.PHONY: all clean fclean re get
