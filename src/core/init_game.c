/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 03:53:44 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/27 19:31:09 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_player_direction(t_game *game)
{
	if (game->map.player_start == 'N')
	{
		game->p1.dir = vector_create(0, -1);
		game->p1.plane = vector_create(0.66, 0);
	}
	else if (game->map.player_start == 'S')
	{
		game->p1.dir = vector_create(0, 1);
		game->p1.plane = vector_create(0.66, 0);
	}
	else if (game->map.player_start == 'E')
	{
		game->p1.dir = vector_create(1, 0);
		game->p1.plane = vector_create(0, 0.66);
	}
	else if (game->map.player_start == 'W')
	{
		game->p1.dir = vector_create(-1, 0);
		game->p1.plane = vector_create(0, 0.66);
	}
}

void	init_player(t_game *game)
{
	game->p1.pos = vector_create(game->map.player_pos.x + 0.5f,
			game->map.player_pos.y + 0.5f);
	set_player_direction(game);
	game->p1.move_speed = MOVE_SPEED;
	game->p1.rot_speed = ROT_SPEED;
	game->p1.keys = (t_keys){0, 0, 0, 0, 0, 0};
}

void	init_game(t_game *game)
{
	init_player(game);
}
