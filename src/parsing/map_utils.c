/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/08 19:45:02 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**copy_map(t_game *game)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < game->map.height)
	{
		temp[i] = ft_strdup(game->map.grid[i]);
		if (!temp[i])
		{
			free_map_copy(temp, i);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

void	free_map_copy(char **temp, int height)
{
	int	i;

	if (!temp)
		return ;
	i = -1;
	while (++i < height)
		free(temp[i]);
	free(temp);
}
