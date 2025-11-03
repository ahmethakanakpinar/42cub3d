/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 00:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 00:33:40 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_valid_texture_file(char *path)
{
	int		fd;
	char	*dot;
	char	*slash;
	char	*filename;

	if (!path || !*path)
		return (false);
	dot = ft_strrchr(path, '.');
	if (!dot || ft_strncmp(dot, ".xpm", 5) != 0)
		return (ft_putendl_fd("Error\nTexture must be .xpm file", 2), false);
	if (dot[4] != '\0')
		return (ft_putendl_fd("Error\nTexture must be .xpm file", 2), false);
	slash = ft_strrchr(path, '/');
	if (slash)
		filename = slash + 1;
	else
		filename = path;
	if (filename == dot)
		return (ft_putendl_fd("Error\nInvalid texture filename", 2), false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nTexture file not found", 2), false);
	close(fd);
	return (true);
}

static bool	parse_single_texture(char *line, char **texture, char *identifier)
{
	char	*ptr;
	char	*path;
	size_t	len;

	ptr = skip_spaces(line);
	if (ft_strncmp(ptr, identifier, 2) != 0)
		return (true);
	if (!(ptr[2] == ' ' || ft_isspace(ptr[2])))
		return (true);
	ptr = skip_spaces(ptr + 2);
	len = 0;
	while (ptr[len] && ptr[len] != '\n')
		len++;
	path = ft_substr(ptr, 0, len);
	if (!path)
		return (false);
	if (!is_valid_texture_file(path))
		return (free(path), false);
	if (*texture)
		return (free(path), ft_putendl_fd("Error\nDuplicate texture", 2),
			false);
	*texture = path;
	return (true);
}

bool	parse_textures(t_game *game)
{
	char	*line;

	game->fd_map = open(game->map_path, O_RDONLY);
	if (game->fd_map == -1)
		return (read_error(game), false);
	line = get_next_line(game->fd_map);
	while (line)
	{
		if (!parse_single_texture(line, &game->map.north, "NO"))
			return (free(line), close(game->fd_map), false);
		if (!parse_single_texture(line, &game->map.south, "SO"))
			return (free(line), close(game->fd_map), false);
		if (!parse_single_texture(line, &game->map.west, "WE"))
			return (free(line), close(game->fd_map), false);
		if (!parse_single_texture(line, &game->map.east, "EA"))
			return (free(line), close(game->fd_map), false);
		free(line);
		line = get_next_line(game->fd_map);
	}
	close(game->fd_map);
	if (!game->map.north || !game->map.south || !game->map.west
		|| !game->map.east)
		return (ft_putendl_fd("Error\nMissing texture(s)", 2), false);
	return (true);
}
