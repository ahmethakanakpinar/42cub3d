/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 02:14:58 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/13 03:03:32 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_valid_pos(char **map, int height, int width, t_vector pos)
{
	int	line_len;

	if (pos.y < 0 || pos.y >= height || pos.x < 0 || pos.x >= width)
		return (false);
	line_len = ft_strlen(map[(int)pos.y]);
	if (pos.x >= line_len)
		return (false);
	if (map[(int)pos.y][(int)pos.x] == ' ')
		return (false);
	return (true);
}

static bool	flood_fill_recursive(char **map, int h, int w, t_vector pos)
{
	if (!is_valid_pos(map, h, w, pos))
		return (false);
	if (map[(int)pos.y][(int)pos.x] == '1'
		|| map[(int)pos.y][(int)pos.x] == 'V')
		return (true);
	if (!is_walkable(map[(int)pos.y][(int)pos.x]))
		return (false);
	map[(int)pos.y][(int)pos.x] = 'V';
	if (!flood_fill_recursive(map, h, w, vector_create(pos.x + 1, pos.y)))
		return (false);
	if (!flood_fill_recursive(map, h, w, vector_create(pos.x - 1, pos.y)))
		return (false);
	if (!flood_fill_recursive(map, h, w, vector_create(pos.x, pos.y + 1)))
		return (false);
	if (!flood_fill_recursive(map, h, w, vector_create(pos.x, pos.y - 1)))
		return (false);
	return (true);
}

bool	flood_fill(char **map, int height, int width, t_vector start)
{
	return (flood_fill_recursive(map, height, width, start));
}

bool	is_map_valid(t_game *game)
{
	char		**temp_map;
	t_vector	start;

	temp_map = copy_map(game);
	if (!temp_map)
		return (ft_putendl_fd("Error\nFailed to create map copy", 2), false);
	start.x = (int)game->map.player_pos.x;
	start.y = (int)game->map.player_pos.y;
	if (!flood_fill(temp_map, game->map.height, game->map.width, start))
	{
		free_map_copy(temp_map, game->map.height);
		return (ft_putendl_fd("Error\nMap is not properly enclosed", 2),
			false);
	}
	free_map_copy(temp_map, game->map.height);
	return (true);
}
