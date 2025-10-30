/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/30 14:44:03 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	render_frame(t_game *game)
{
	update_player(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!validate_map_arguments(argc, argv))
		return (1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	if (!check_map_validation(game, argv[1]))
		return (1);
	if (!init_mlx(game))
		return (cleanup_game(game), 1);
	init_game(game);
	create_textures(game);
	hook_n_run(game);
	cleanup_game(game);
	return (0);
}
