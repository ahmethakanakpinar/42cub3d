/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:05:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 03:05:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*get_base_path(char *texture_path, size_t len)
{
	char	*base;
	char	*temp;
	size_t	i;

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
	return (base);
}

static char	*get_frame_str(int frame)
{
	char	*frame_num;
	char	*frame_str;

	frame_num = ft_itoa(frame);
	if (frame < 10)
	{
		frame_str = ft_strjoin("0", frame_num);
		free(frame_num);
	}
	else
		frame_str = frame_num;
	return (frame_str);
}

char	*create_frame_path(char *texture_path, int frame)
{
	char	*base;
	char	*frame_str;
	char	*temp;
	char	*path;
	size_t	len;

	len = ft_strlen(texture_path);
	if (len < 4 || ft_strncmp(texture_path + len - 4, ".xpm", 4) != 0)
		return (NULL);
	base = get_base_path(texture_path, len);
	if (!base)
		return (NULL);
	frame_str = get_frame_str(frame);
	temp = ft_strjoin(base, frame_str);
	free(base);
	free(frame_str);
	path = ft_strjoin(temp, ".xpm");
	free(temp);
	return (path);
}

bool	has_frame_number(char *texture_path)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(texture_path);
	if (len < 8)
		return (false);
	i = len - 5;
	while (i > 0 && texture_path[i] != '_')
		i--;
	if (i > 0 && texture_path[i] == '_' && texture_path[i + 1] >= '0'
		&& texture_path[i + 1] <= '9' && texture_path[i + 2] >= '0'
		&& texture_path[i + 2] <= '9')
		return (true);
	return (false);
}
