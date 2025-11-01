/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:17 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/01 23:07:05 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int	y;
	int	tex_y;
	int	color;

	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(game, x, y, game->map.ceiling_color);
		y++;
	}
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos % ray->texture->height;
		if (tex_y < 0)
			tex_y += ray->texture->height;
		ray->tex_pos += ray->tex_step;
		color = get_texture_color(ray->texture, ray->tex_x, tex_y);
		put_pixel(game, x, y, color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		put_pixel(game, x, y, game->map.floor_color);
		y++;
	}
}

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, x);
		set_step(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_dist(game, &ray);
		get_texture(game, &ray);
		draw_vertical_line(game, x, &ray);
		x++;
	}
}
