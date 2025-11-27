/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:07 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/27 19:27:57 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_valid_position(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;
	double	margin;

	margin = 0.2;
	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_x >= game->map.width || map_y < 0
		|| map_y >= game->map.height)
		return (false);
	if (game->map.grid[map_y][map_x] == '1')
		return (false);
	if (game->map.grid[(int)(new_y - margin)][(int)(new_x - margin)] == '1')
		return (false);
	if (game->map.grid[(int)(new_y - margin)][(int)(new_x + margin)] == '1')
		return (false);
	if (game->map.grid[(int)(new_y + margin)][(int)(new_x - margin)] == '1')
		return (false);
	if (game->map.grid[(int)(new_y + margin)][(int)(new_x + margin)] == '1')
		return (false);
	return (true);
}

static void	move_forward_backward(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->p1.pos.x + game->p1.dir.x * game->p1.move_speed * direction;
	new_y = game->p1.pos.y + game->p1.dir.y * game->p1.move_speed * direction;
	if (is_valid_position(game, new_x, game->p1.pos.y))
		game->p1.pos.x = new_x;
	if (is_valid_position(game, game->p1.pos.x, new_y))
		game->p1.pos.y = new_y;
}

static void	move_left_right(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->p1.pos.x + game->p1.plane.x * game->p1.move_speed * direction;
	new_y = game->p1.pos.y + game->p1.plane.y * game->p1.move_speed * direction;
	if (is_valid_position(game, new_x, game->p1.pos.y))
		game->p1.pos.x = new_x;
	if (is_valid_position(game, game->p1.pos.x, new_y))
		game->p1.pos.y = new_y;
}

void	update_player(t_game *game)
{
	if (game->p1.keys.w)
		move_forward_backward(game, 1);
	if (game->p1.keys.s)
		move_forward_backward(game, -1);
	if (game->p1.keys.a)
		move_left_right(game, -1);
	if (game->p1.keys.d)
		move_left_right(game, 1);
	rotate(game);
}
