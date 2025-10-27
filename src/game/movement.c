/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:07 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/28 01:10:01 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_valid_move(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_x >= game->map.width
		|| map_y < 0 || map_y >= game->map.height)
		return (false);
	if (game->map.grid[map_y][map_x] == '1')
		return (false);
	return (true);
}

static void	move_forward_back(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->p1.keys.w)
	{
		new_x = game->p1.pos.x + game->p1.dir.x * game->p1.move_speed;
		new_y = game->p1.pos.y + game->p1.dir.y * game->p1.move_speed;
		if (is_valid_move(game, new_x, new_y))
		{
			game->p1.pos.x = new_x;
			game->p1.pos.y = new_y;
		}
	}
	if (game->p1.keys.s)
	{
		new_x = game->p1.pos.x - game->p1.dir.x * game->p1.move_speed;
		new_y = game->p1.pos.y - game->p1.dir.y * game->p1.move_speed;
		if (is_valid_move(game, new_x, new_y))
		{
			game->p1.pos.x = new_x;
			game->p1.pos.y = new_y;
		}
	}
}

static void	move_left_right(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->p1.keys.a)
	{
		new_x = game->p1.pos.x - game->p1.plane.x * game->p1.move_speed;
		new_y = game->p1.pos.y - game->p1.plane.y * game->p1.move_speed;
		if (is_valid_move(game, new_x, new_y))
		{
			game->p1.pos.x = new_x;
			game->p1.pos.y = new_y;
		}
	}
	if (game->p1.keys.d)
	{
		new_x = game->p1.pos.x + game->p1.plane.x * game->p1.move_speed;
		new_y = game->p1.pos.y + game->p1.plane.y * game->p1.move_speed;
		if (is_valid_move(game, new_x, new_y))
		{
			game->p1.pos.x = new_x;
			game->p1.pos.y = new_y;
		}
	}
}

static void	rotate(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = game->p1.rot_speed;
	if (game->p1.keys.left)
	{
		old_dir_x = game->p1.dir.x;
		game->p1.dir.x = game->p1.dir.x * cos(rot_speed)
			- game->p1.dir.y * sin(rot_speed);
		game->p1.dir.y = old_dir_x * sin(rot_speed)
			+ game->p1.dir.y * cos(rot_speed);
		old_plane_x = game->p1.plane.x;
		game->p1.plane.x = game->p1.plane.x * cos(rot_speed)
			- game->p1.plane.y * sin(rot_speed);
		game->p1.plane.y = old_plane_x * sin(rot_speed)
			+ game->p1.plane.y * cos(rot_speed);
	}
	if (game->p1.keys.right)
	{
		old_dir_x = game->p1.dir.x;
		game->p1.dir.x = game->p1.dir.x * cos(-rot_speed)
			- game->p1.dir.y * sin(-rot_speed);
		game->p1.dir.y = old_dir_x * sin(-rot_speed)
			+ game->p1.dir.y * cos(-rot_speed);
		old_plane_x = game->p1.plane.x;
		game->p1.plane.x = game->p1.plane.x * cos(-rot_speed)
			- game->p1.plane.y * sin(-rot_speed);
		game->p1.plane.y = old_plane_x * sin(-rot_speed)
			+ game->p1.plane.y * cos(-rot_speed);
	}
}

void	update_player(t_game *game)
{
	move_forward_back(game);
	move_left_right(game);
	rotate(game);
}
