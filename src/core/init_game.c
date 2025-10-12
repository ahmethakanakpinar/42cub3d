/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 03:53:44 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/12 05:25:40 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"


void	init_map(t_game *game)
{
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.floor_color = 0;
	game->map.ceiling_color = 0;
	
    // init_colors(game);
	game->map.player_start = '\0';
	game->map.player_pos = vector_create(0, 0);
}

void	init_game(t_game *game)
{
	init_map(game);

	
}