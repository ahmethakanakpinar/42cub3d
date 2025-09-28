/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:49:41 by aakpinar          #+#    #+#             */
/*   Updated: 2025/09/28 12:51:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	

	if (game->fd_map != -1)
		close(game->fd_map);
	free(game);
}