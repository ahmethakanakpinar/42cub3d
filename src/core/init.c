/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:25:57 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 03:02:57 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (false);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!(game->img))
		return (false);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!(game->addr))
		return (false);
	return (true);
}

void	create_textures(t_game *game)
{
	game->anim_frame = 0;
	game->anim_counter = 0;
	if (!load_texture_frames(game, game->north, game->map.north))
	{
		printf("Error\nFailed to load north textures\n");
		cleanup_game(game);
		exit(1);
	}
	if (!load_texture_frames(game, game->south, game->map.south)
		|| !load_texture_frames(game, game->east, game->map.east)
		|| !load_texture_frames(game, game->west, game->map.west))
	{
		printf("Error\nFailed to load textures\n");
		cleanup_game(game);
		exit(1);
	}
}
