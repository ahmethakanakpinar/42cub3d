/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:25:57 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/28 01:09:14 by malbayra         ###   ########.fr       */
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

static void	free_textures(t_texture *north, t_texture *south, t_texture *east,
	t_texture *west)
{
if (north)
	free(north);
if (south)
	free(south);
if (east)
	free(east);
if (west)
	free(west);
}

void	create_textures(t_game *game)
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;

	north = texture_create(game, game->map.north);
	south = texture_create(game, game->map.south);
	east = texture_create(game, game->map.east);
	west = texture_create(game, game->map.west);
	if (!north || !south || !east || !west)
	{
		printf("Error\nFailed to load textures\n");
		free_textures(north, south, east, west);
		cleanup_game(game);
		exit(1);
	}
	game->north = *north;
	game->south = *south;
	game->east = *east;
	game->west = *west;
	free_textures(north, south, east, west);
}
