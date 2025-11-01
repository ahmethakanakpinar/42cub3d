/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:22 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/01 21:53:56 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir.x = game->p1.dir.x + game->p1.plane.x * camera_x;
	ray->ray_dir.y = game->p1.dir.y + game->p1.plane.y * camera_x;
	ray->map.x = (int)game->p1.pos.x;
	ray->map.y = (int)game->p1.pos.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

static void	set_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->p1.pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - game->p1.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->p1.pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - game->p1.pos.y)
			* ray->delta_dist.y;
	}
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map.grid[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

static void	calculate_wall_dist(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - game->p1.pos.x
				+ (1 - ray->step.x) / 2) / ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - game->p1.pos.y
				+ (1 - ray->step.y) / 2) / ray->ray_dir.y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->step.x > 0)
		ray->texture = &game->east;
	else if (ray->side == 0 && ray->step.x < 0)
		ray->texture = &game->west;
	else if (ray->side == 1 && ray->step.y > 0)
		ray->texture = &game->south;
	else
		ray->texture = &game->north;
	if (ray->side == 0)
		ray->wall_x = game->p1.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = game->p1.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)ray->texture->width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
	ray->tex_step = 1.0 * ray->texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->tex_step;
}
