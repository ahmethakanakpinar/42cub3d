/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 05:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 08:20:53 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_remaining_lines(t_game *game, char *line)
{
	free(line);
	line = get_next_line(game->fd_map);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			free(line);
			close(game->fd_map);
			return (-1);
		}
		free(line);
		line = get_next_line(game->fd_map);
	}
	return (0);
}

static int	count_map_liness(t_game *game, char *line, int count,
		bool found_map)
{
	while (line)
	{
		if (!found_map && (line[0] == '1' || line[0] == ' '))
			found_map = true;
		if (found_map)
		{
			if (line[0] == '\n' || line[0] == '\0')
			{
				if (check_remaining_lines(game, line) == -1)
					return (-1);
				break ;
			}
			count++;
		}
		free(line);
		line = get_next_line(game->fd_map);
	}
	return (count);
}

int	count_map_lines(t_game *game)
{
	char	*line;
	int		count;
	bool	found_map;

	count = 0;
	found_map = false;
	game->fd_map = open(game->map_path, O_RDONLY);
	if (game->fd_map == -1)
		return (0);
	line = get_next_line(game->fd_map);
	count = count_map_liness(game, line, count, found_map);
	close(game->fd_map);
	return (count);
}

char	*trim_newline(char *line)
{
	int		len;
	char	*trimmed;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		trimmed = ft_substr(line, 0, len - 1);
		free(line);
		return (trimmed);
	}
	return (line);
}
