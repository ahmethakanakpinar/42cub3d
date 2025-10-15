/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:40:49 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/15 03:51:20 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../include/constants.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		move_speed;
	double		rot_speed;
	t_keys		keys;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	char		player_start;
	t_vector	player_pos;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fd_map;
	char		*map_path;
	t_map		map;
	t_player	p1;
}				t_game;

bool		validate_map_arguments(int argc, char **argv);
void		read_error(t_game *game);
void		cleanup_game(t_game *game);
bool		check_map_validation(t_game *game, char *path);

int			ft_isspace(int c);
bool		print_color_error(int f_count, int c_count);
bool		print_texture_error(int no, int so, int we, int ea);
bool		check_element_counts(t_game *game);
bool		parse_colors(t_game *game);
bool		parse_textures(t_game *game);
int			rgb_to_int(int r, int g, int b);
bool		is_valid_rgb(int r, int g, int b);
char		*skip_spaces(char *str);
bool		parse_rgb_values(char *line, int *r, int *g, int *b);
bool		parse_map(t_game *game);
int			count_map_lines(t_game *game);
char		*trim_newline(char *line);
bool		check_characters(t_game *game);
bool		validate_map_structure(t_game *game);
bool		validate_map_walls(t_game *game);
bool		init_mlx(t_game *game);
void		init_game(t_game *game);
void		init_player(t_game *game);
void		hook_n_run(t_game *game);
t_vector	vector_create(double x, double y);
bool		is_map_valid(t_game *game);
bool		flood_fill(char **map, int height, int width, t_vector start);
char		**copy_map(t_game *game);
void		free_map_copy(char **temp, int height);
#endif
