/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:55:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/15 03:41:40 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	validate_map_arguments(int argc, char **argv)
{
	const char	*dot;

	if (argc != 2)
	{
		printf("Error: Usage: ./cub3d <map_file.cub>\n");
		return (false);
	}
	dot = ft_strrchr(argv[1], '.');
	if (!dot || ft_strncmp(dot, ".cub", 4) != 0)
	{
		printf("Error: Invalid file extension. Expected .cub file\n");
		return (false);
	}
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
