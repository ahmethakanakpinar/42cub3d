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
	   $(SRCDIR)/parsing/map_validation.c \
	   $(SRCDIR)/parsing/map_walls.c \
	   $(SRCDIR)/parsing/map_parser.c \
	   $(SRCDIR)/parsing/map_counter.c \
	   $(SRCDIR)/parsing/element_parser.c \
	   $(SRCDIR)/parsing/file_reader.c \
	   $(SRCDIR)/core/init.c \
	   $(SRCDIR)/core/init_game.c \
	   $(SRCDIR)/core/vector.c \
	   $(SRCDIR)/game/input.c \
	   $(SRCDIR)/game/movement.c \
	   $(SRCDIR)/game/player.c \
	   $(SRCDIR)/rendering/drawing.c \
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

test: $(NAME)
	@echo "Running map validation tests..."
	@./test_maps.sh

test-valid: $(NAME)
	@echo "Testing VALID maps:"
	@for map in maps/valid/*.cub; do \
		echo "Testing $$map..."; \
		./$(NAME) "$$map" || true; \
	done

test-invalid: $(NAME)
	@echo "Testing INVALID maps (should fail):"
	@for map in maps/invalid/*.cub; do \
		echo "Testing $$map..."; \
		./$(NAME) "$$map" 2>&1 | head -1 || true; \
		echo "---"; \
	done

info:
	@echo "╔═══════════════════════════════════════════════════╗"
	@echo "║            CUB3D PROJECT INFO                     ║"
	@echo "╚═══════════════════════════════════════════════════╝"
	@echo "Name:           $(NAME)"
	@echo "CC:             $(CC)"
	@echo "CFLAGS:         $(CFLAGS)"
	@echo ""
	@echo "Source files:   $(words $(SRCS))"
	@echo "Object files:   $(words $(OBJS))"
	@echo ""
	@echo "Parsing files:  $(shell ls -1 $(SRCDIR)/parsing/*.c 2>/dev/null | wc -l)"
	@echo "Core files:     $(shell ls -1 $(SRCDIR)/core/*.c 2>/dev/null | wc -l)"
	@echo "Game files:     $(shell ls -1 $(SRCDIR)/game/*.c 2>/dev/null | wc -l)"
	@echo "Rendering files:$(shell ls -1 $(SRCDIR)/rendering/*.c 2>/dev/null | wc -l)"
	@echo "Utils files:    $(shell ls -1 $(SRCDIR)/utils/*.c 2>/dev/null | wc -l)"
	@echo ""
	@echo "Valid maps:     $(shell ls -1 maps/valid/*.cub 2>/dev/null | wc -l)"
	@echo "Invalid maps:   $(shell ls -1 maps/invalid/*.cub 2>/dev/null | wc -l)"

help:
	@echo "╔═══════════════════════════════════════════════════╗"
	@echo "║            CUB3D MAKEFILE HELP                    ║"
	@echo "╚═══════════════════════════════════════════════════╝"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Compile the project"
	@echo "  make clean        - Remove object files"
	@echo "  make fclean       - Remove object files and binary"
	@echo "  make re           - Recompile everything"
	@echo "  make get          - Clone MinilibX library"
	@echo "  make norm         - Check norminette compliance"
	@echo "  make test         - Run all map tests"
	@echo "  make test-valid   - Test only valid maps"
	@echo "  make test-invalid - Test only invalid maps"
	@echo "  make info         - Show project information"
	@echo "  make help         - Show this help message"

.PHONY: all clean fclean re get norm test test-valid test-invalid info help