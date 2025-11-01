/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:09 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/01 21:54:09 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	rotate_left(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

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

static void	rotate_right(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

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

void	rotate(t_game *game)
{
	double	rot_speed;

	rot_speed = game->p1.rot_speed;
	if (game->p1.keys.left)
		rotate_left(game, rot_speed);
	if (game->p1.keys.right)
		rotate_right(game, rot_speed);
}
