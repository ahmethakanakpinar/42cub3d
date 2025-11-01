/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 00:33:36 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	validate_map_arguments(int argc, char **argv)
{
	const char	*dot;
	const char	*slash;
	const char	*filename;

	if (argc != 2)
		return (printf("Error: Usage: ./cub3d <map_file.cub>\n"), false);
	dot = ft_strrchr(argv[1], '.');
	if (!dot || ft_strncmp(dot, ".cub", 5) != 0 || dot[4] != '\0')
		return (printf("Error: Invalid file extension. Expected .cub file\n"),
			false);
	slash = ft_strrchr(argv[1], '/');
	if (slash)
		filename = slash + 1;
	else
		filename = argv[1];
	if (filename == dot || (filename[0] == '.' && filename + 1 == dot))
		return (printf("Error: Invalid filename. File must have a name\n"),
			false);
	return (true);
}

bool	check_map_validation(t_game *game, char *path)
{
	game->map_path = path;
	if (!check_element_counts(game))
		return (cleanup_game(game), false);
	if (!parse_colors(game))
		return (cleanup_game(game), false);
	if (!parse_textures(game))
		return (cleanup_game(game), false);
	if (!parse_map(game))
		return (cleanup_game(game), false);
	if (!validate_map_structure(game))
		return (cleanup_game(game), false);
	if (!is_map_valid(game))
		return (cleanup_game(game), false);
	return (true);
}
