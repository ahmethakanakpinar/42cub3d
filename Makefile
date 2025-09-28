NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
INCDIR = include
LIBFTDIR = libs/libft
GNLDIR = libs/get_next_line

SRCS = $(SRCDIR)/main.c \
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

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft $(GNL)

$(LIBFT):
	make -C $(LIBFTDIR)

$(GNL):
	make -C $(GNLDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(GNLDIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(GNLDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(GNLDIR) fclean

re: fclean all

.PHONY: all clean fclean re
