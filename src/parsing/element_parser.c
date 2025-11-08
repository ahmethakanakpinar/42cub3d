/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:42 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/09 01:41:13 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	parse_single_color(char *line, int *color, char identifier)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	ptr = skip_spaces(line);
	if (*ptr != identifier || !(ptr[1] == ' ' || ft_isspace(ptr[1])))
		return (true);
	ptr += 2;
	if (!parse_rgb_values(ptr, &r, &g, &b))
		return (false);
	*color = rgb_to_int(r, g, b);
	return (true);
}

bool	parse_colors(t_game *game)
{
	char	*line;

	game->fd_map = open(game->map_path, O_RDONLY);
	if (game->fd_map == -1)
		return (read_error(game), exit(1), false);
	line = get_next_line(game->fd_map);
	while (line)
	{
		if (!parse_single_color(line, &game->map.floor_color, 'F'))
			return (free(line), close(game->fd_map), false);
		if (!parse_single_color(line, &game->map.ceiling_color, 'C'))
			return (free(line), close(game->fd_map), false);
		free(line);
		line = get_next_line(game->fd_map);
	}
	close(game->fd_map);
	return (true);
}

bool	parse_single_value(char **ptr, int *value)
{
	int	digit_count;

	*ptr = skip_spaces(*ptr);
	digit_count = get_digit_count(*ptr);
	if (digit_count == 0 || digit_count > 3)
		return (ft_putendl_fd("Error\nRGB value must be 1-3 digits", 2), false);
	*value = ft_atoi(*ptr);
	*ptr += digit_count;
	return (true);
}
