/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/15 03:51:18 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hook_n_run(t_game *game)
{
	(void)game;
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
	hook_n_run(game);
	cleanup_game(game);
	return (0);
}
