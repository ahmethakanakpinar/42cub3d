/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 03:05:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	load_single_frame(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (false);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (false);
	texture->path = path;
	return (true);
}

static bool	load_all_same_texture(t_game *game, t_texture *frames,
		char *first_frame_path)
{
	int		i;
	char	*path;

	i = 1;
	while (i < ANIM_FRAMES)
	{
		path = ft_strdup(first_frame_path);
		if (!path)
			return (false);
		if (!load_single_frame(game, &frames[i], path))
		{
			free(path);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	load_remaining_frames(t_game *game, t_texture *frames,
		char *texture_path)
{
	int		i;
	char	*path;

	i = 2;
	while (i < ANIM_FRAMES)
	{
		path = create_frame_path(texture_path, i + 1);
		if (!path)
			return (false);
		if (!load_single_frame(game, &frames[i], path))
		{
			free(path);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	load_texture_frames(t_game *game, t_texture *frames,
		char *texture_path)
{
	char	*path;

	path = ft_strdup(texture_path);
	if (!path || !load_single_frame(game, &frames[0], path))
		return (free(path), false);
	if (!has_frame_number(texture_path))
		return (load_all_same_texture(game, frames, texture_path));
	path = create_frame_path(texture_path, 2);
	if (!path)
		return (load_all_same_texture(game, frames, texture_path));
	if (!load_single_frame(game, &frames[1], path))
		return (free(path), load_all_same_texture(game, frames, texture_path));
	return (load_remaining_frames(game, frames, texture_path));
}

void	update_animation(t_game *game)
{
	game->anim_counter++;
	if (game->anim_counter >= ANIM_SPEED)
	{
		game->anim_counter = 0;
		game->anim_frame++;
		if (game->anim_frame >= ANIM_FRAMES)
			game->anim_frame = 0;
	}
}
