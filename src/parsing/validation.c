/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:48 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/07 02:12:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	validate_color(char *line, int *f_count, int *c_count)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	if (line && line[i])
	{
		if (line[i] == 'F' && (line[i + 1] == ' '
				|| ft_isspace(line[i + 1])))
			(*f_count)++;
		else if (line[i] == 'C' && (line[i + 1] == ' '
				|| ft_isspace(line[i + 1])))
			(*c_count)++;
	}
}

static void	check_texture_type(char *line, int i, int *counts)
{
	if (line[i] == 'N' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		counts[0]++;
	else if (line[i] == 'S' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		counts[1]++;
	else if (line[i] == 'W' && line[i + 1] == 'E'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		counts[2]++;
	else if (line[i] == 'E' && line[i + 1] == 'A'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		counts[3]++;
}

static void	validate_texture(char *line, int *counts)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	if (line && line[i])
		check_texture_type(line, i, counts);
}

static bool	validate_counts(int *counts)
{
	if (counts[0] != 1 || counts[1] != 1
		|| counts[2] != 1 || counts[3] != 1)
		return (print_texture_error(counts[0],
				counts[1], counts[2], counts[3]));
	if (counts[4] != 1 || counts[5] != 1)
		return (print_color_error(counts[4], counts[5]));
	return (true);
}

bool	check_element_counts(t_game *game)
{
	char	*line;
	int		counts[6];
	int		i;

	game->fd_map = open(game->map_path, O_RDONLY);
	if (game->fd_map == -1)
		return (read_error(game), exit(1), false);
	i = -1;
	while (++i < 6)
		counts[i] = 0;
	line = get_next_line(game->fd_map);
	while (line)
	{
		validate_texture(line, counts);
		validate_color(line, &counts[4], &counts[5]);
		free(line);
		line = get_next_line(game->fd_map);
	}
	close(game->fd_map);
	return (validate_counts(counts));
}
