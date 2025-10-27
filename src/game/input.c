/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:05 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/28 01:09:44 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		game->p1.keys.w = 1;
	if (keycode == KEY_S)
		game->p1.keys.s = 1;
	if (keycode == KEY_A)
		game->p1.keys.a = 1;
	if (keycode == KEY_D)
		game->p1.keys.d = 1;
	if (keycode == KEY_LEFT)
		game->p1.keys.left = 1;
	if (keycode == KEY_RIGHT)
		game->p1.keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->p1.keys.w = 0;
	if (keycode == KEY_S)
		game->p1.keys.s = 0;
	if (keycode == KEY_A)
		game->p1.keys.a = 0;
	if (keycode == KEY_D)
		game->p1.keys.d = 0;
	if (keycode == KEY_LEFT)
		game->p1.keys.left = 0;
	if (keycode == KEY_RIGHT)
		game->p1.keys.right = 0;
	return (0);
}
