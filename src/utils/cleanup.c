/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:49:41 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/15 03:51:15 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cleanup_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map.north)
		free(game->map.north);
	if (game->map.south)
		free(game->map.south);
	if (game->map.west)
		free(game->map.west);
	if (game->map.east)
		free(game->map.east);
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->fd_map != -1)
		close(game->fd_map);
	free(game);
}
