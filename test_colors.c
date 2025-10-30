/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:09:45 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/30 15:18:47 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	if (!check_map_validation(game, "maps/valid/simple.cub"))
		return (1);
	printf("Floor Color (F 220,100,0):\n");
	printf("  RGB Values: R=%d, G=%d, B=%d\n",
		(game->map.floor_color >> 16) & 0xFF,
		(game->map.floor_color >> 8) & 0xFF, game->map.floor_color & 0xFF);
	printf("  Hex: 0x%06X\n", game->map.floor_color);
	printf("\nCeiling Color (C 225,30,0):\n");
	printf("  RGB Values: R=%d, G=%d, B=%d\n",
		(game->map.ceiling_color >> 16) & 0xFF,
		(game->map.ceiling_color >> 8) & 0xFF, game->map.ceiling_color & 0xFF);
	printf("  Hex: 0x%06X\n", game->map.ceiling_color);
	printf("\nPlayer Position:\n");
	printf("  X: %.2f, Y: %.2f\n", game->map.player_pos.x,
		game->map.player_pos.y);
	printf("  Start Direction: %c\n", game->map.player_start);
	cleanup_game(game);
	return (0);
}
