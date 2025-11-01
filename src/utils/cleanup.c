/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:49:41 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/01 21:44:38 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_map_textures(t_game *game)
{
	if (game->map.north)
		free(game->map.north);
	if (game->map.south)
		free(game->map.south);
	if (game->map.west)
		free(game->map.west);
	if (game->map.east)
		free(game->map.east);
}

static void	free_map_grid(t_game *game)
{
	int	i;

	if (!game->map.grid)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->north.img)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx, game->west.img);
	free_map_textures(game);
	free_map_grid(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->fd_map != -1)
		close(game->fd_map);
	free(game);
}
