/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/12 03:37:02 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

    
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
		return (cleanup_game(game),1);
	
	return (0);
}