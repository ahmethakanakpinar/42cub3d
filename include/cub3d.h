/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:40:49 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 07:12:03 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../include/constants.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
	char			*path;
}					t_texture;

typedef struct s_ray
{
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		delta_dist;
	t_vector_int	map;
	t_vector_int	step;
	double			perp_wall_dist;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			tex_step;
	double			tex_pos;
	t_texture		*texture;
}					t_ray;

typedef struct s_player
{
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
	double			move_speed;
	double			rot_speed;
	t_keys			keys;
}					t_player;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				floor_color;
	int				ceiling_color;
	char			player_start;
	t_vector		player_pos;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;

	t_texture		north[ANIM_FRAMES];
	t_texture		south[ANIM_FRAMES];
	t_texture		east[ANIM_FRAMES];
	t_texture		west[ANIM_FRAMES];

	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				fd_map;
	char			*map_path;
	t_map			map;
	t_player		p1;
	int				anim_frame;
	int				anim_counter;
}					t_game;

void				rotate(t_game *game);
void				init_ray(t_game *game, t_ray *ray, int x);
void				set_step(t_game *game, t_ray *ray);
void				perform_dda(t_game *game, t_ray *ray);
void				calculate_wall_dist(t_game *game, t_ray *ray);
void				get_texture(t_game *game, t_ray *ray);

bool				validate_map_arguments(int argc, char **argv);
void				read_error(t_game *game);
void				cleanup_game(t_game *game);
bool				check_map_validation(t_game *game, char *path);
bool				validate_file_content(t_game *game);

int					ft_isspace(int c);
bool				print_color_error(int f_count, int c_count);
bool				print_texture_error(int no, int so, int we, int ea);
bool				check_element_counts(t_game *game);
bool				parse_colors(t_game *game);
bool				parse_textures(t_game *game);
int					rgb_to_int(int r, int g, int b);
bool				is_valid_rgb(int r, int g, int b);
char				*skip_spaces(char *str);
bool				parse_rgb_values(char *line, int *r, int *g, int *b);
bool				parse_map(t_game *game);
int					count_map_lines(t_game *game);
char				*trim_newline(char *line);
bool				check_characters(t_game *game);
bool				validate_map_structure(t_game *game);
bool				validate_map_walls(t_game *game);
bool				init_mlx(t_game *game);
void				init_game(t_game *game);
void				init_player(t_game *game);
void				hook_n_run(t_game *game);
t_vector			vector_create(double x, double y);
bool				is_map_valid(t_game *game);
bool				flood_fill(char **map, int height, int width,
						t_vector start);
char				**copy_map(t_game *game);
void				free_map_copy(char **temp, int height);
void				create_textures(t_game *game);
t_texture			*texture_create(t_game *game, char *texture_path);
void				put_pixel(t_game *game, int x, int y, int color);
int					get_texture_color(t_texture *texture, int x, int y);
void				draw_vertical_line(t_game *game, int x, t_ray *ray);
void				cast_rays(t_game *game);
void				update_animation(t_game *game);
bool				load_texture_frames(t_game *game, t_texture *frames,
						char *texture_path);
char				*create_frame_path(char *texture_path, int frame);
bool				has_frame_number(char *texture_path);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					close_window(t_game *game);
void				update_player(t_game *game);
#endif
