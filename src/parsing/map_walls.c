/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:10:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/12 04:25:26 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	check_walls(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == '0' || is_player_char(game->map.grid[i][j]))
	{
		if (i == 0 || i == game->map.height - 1)
			return (false);
		if (j == 0 || !game->map.grid[i][j + 1])
			return (false);
		if (game->map.grid[i - 1][j] == ' ' || !game->map.grid[i - 1][j])
			return (false);
		if (game->map.grid[i + 1][j] == ' ' || !game->map.grid[i + 1][j])
			return (false);
		if (game->map.grid[i][j - 1] == ' ')
			return (false);
		if (game->map.grid[i][j + 1] == ' ')
			return (false);
	}
	return (true);
}

bool	validate_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (!check_walls(game, i, j))
				return (ft_putendl_fd("Error\nMap is not closed by walls", 2),
					false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	validate_map_structure(t_game *game)
{
	if (!check_characters(game))
		return (false);
	if (!validate_map_walls(game))
		return (false);
	return (true);
}
