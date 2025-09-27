/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:48 by aakpinar          #+#    #+#             */
/*   Updated: 2025/09/27 23:14:57 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


bool	validate_map_file_extension(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error: Usage: ./cub3d <map_file.cub>\n"), false);
	if (!valid_extension(argv[1]))
		return (printf("Error: Invalid file extension. Expected .cub file\n"), false);
	return (true);
}

bool	valid_extension(char *map)
{
	const char	*dot = ft_strrchr(map, '.');

	if (!dot)
		return (false);
	if (ft_strncmp((char *)dot, ".cub", 4) == 0)
		return (true);
	return (false);
}