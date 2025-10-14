/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/13 02:45:08 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static bool	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	save_player_position(t_game *game, int i, int j)
{
	game->map.player_start = game->map.grid[i][j];
	game->map.player_pos.x = (double)j + 0.5;
	game->map.player_pos.y = (double)i + 0.5;
}

bool	check_characters(t_game *game)
{
	int		i;
	int		j;
	int		player_count;

	player_count = 0;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			if (!is_valid_char(game->map.grid[i][j]))
				return (ft_putendl_fd("Error\nInvalid character in map", 2),
					false);
			if (is_player_char(game->map.grid[i][j]))
			{
				save_player_position(game, i, j);
				player_count++;
			}
		}
	}
	if (player_count != 1)
		return (ft_putendl_fd("Error\nMap must have exactly one player", 2),
			false);
	return (true);
}
