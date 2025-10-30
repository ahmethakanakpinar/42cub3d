/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:24 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/30 14:42:30 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_texture	*texture_create(t_game *game, char *texture_path)
{
	t_texture	*texture;

	if (!game || !game->mlx || !texture_path)
	{
		return (NULL);
	}
	texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!texture)
	{
		printf("Error: Failed to allocate memory for texture\n");
		return (NULL);
	}
	texture->img = mlx_xpm_file_to_image(game->mlx, texture_path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Failed to load texture: %s\n", texture_path);
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (texture);
}
