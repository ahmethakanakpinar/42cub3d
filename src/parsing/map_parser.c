/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:46 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/12 05:12:54 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	skip_to_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->fd_map);
	while (line)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			game->map.grid[i] = trim_newline(line);
			return (true);
		}
		free(line);
		line = get_next_line(game->fd_map);
	}
	return (false);
}

static void	calculate_map_width(t_game *game)
{
	int	i;
	int	len;

	game->map.width = 0;
	i = 0;
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
}

static bool	read_map_lines(t_game *game)
{
	int		i;
	char	*line;

	if (!skip_to_map(game))
		return (false);
	i = 1;
	while (i < game->map.height)
	{
		line = get_next_line(game->fd_map);
		game->map.grid[i] = trim_newline(line);
		i++;
	}
	game->map.grid[i] = NULL;
	close(game->fd_map);
	calculate_map_width(game);
	return (true);
}

bool	parse_map(t_game *game)
{
	game->map.height = count_map_lines(game);
	if (game->map.height == 0)
		return (ft_putendl_fd("Error\nEmpty map", 2), false);
	if (game->map.height == -1)
		return (ft_putendl_fd("Error\nEmpty line in map", 2), false);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (ft_putendl_fd("Error\nMemory allocation failed", 2), false);
	game->fd_map = open(game->map_path, O_RDONLY);
	if (game->fd_map == -1)
		return (false);
	return (read_map_lines(game));
}
