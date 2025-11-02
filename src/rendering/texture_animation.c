/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:00:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 03:02:58 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*create_frame_path(char *texture_path, int frame)
{
	char	*frame_num;
	char	*frame_str;
	char	*base;
	char	*path;
	char	*temp;
	size_t	len;
	size_t	i;

	len = ft_strlen(texture_path);
	if (len < 4 || ft_strncmp(texture_path + len - 4, ".xpm", 4) != 0)
		return (NULL);
	i = len - 5;
	while (i > 0 && texture_path[i] != '_')
		i--;
	if (i > 0 && texture_path[i] == '_' && texture_path[i + 1] >= '0'
		&& texture_path[i + 1] <= '9')
		base = ft_substr(texture_path, 0, i + 1);
	else
	{
		base = ft_substr(texture_path, 0, len - 4);
		temp = ft_strjoin(base, "_");
		free(base);
		base = temp;
	}
	if (!base)
		return (NULL);
	frame_num = ft_itoa(frame);
	if (frame < 10)
	{
		frame_str = ft_strjoin("0", frame_num);
		free(frame_num);
	}
	else
		frame_str = frame_num;
	temp = ft_strjoin(base, frame_str);
	free(base);
	free(frame_str);
	path = ft_strjoin(temp, ".xpm");
	free(temp);
	return (path);
}

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

bool	load_texture_frames(t_game *game, t_texture *frames,
		char *texture_path)
{
	int		i;
	char	*path;

	i = 0;
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
