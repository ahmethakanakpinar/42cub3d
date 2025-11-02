/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:32:20 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 17:08:04 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_valid_identifier(char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		return (true);
	if (line[i] == 'S' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		return (true);
	if (line[i] == 'W' && line[i + 1] == 'E'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		return (true);
	if (line[i] == 'E' && line[i + 1] == 'A'
		&& (line[i + 2] == ' ' || ft_isspace(line[i + 2])))
		return (true);
	if ((line[i] == 'F' || line[i] == 'C')
		&& (line[i + 1] == ' ' || ft_isspace(line[i + 1])))
		return (true);
	return (false);
}

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_map_line(char *line)
{
	if (line[0] == '1' || line[0] == ' ')
		return (true);
	return (false);
}

static bool	is_valid_line(char *line)
{
	int	i;

	if (!line || !line[0])
		return (true);
	if (is_empty_line(line))
		return (true);
	if (is_map_line(line))
		return (true);
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] && is_valid_identifier(line, i))
		return (true);
	return (false);
}
