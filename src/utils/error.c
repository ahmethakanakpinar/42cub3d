/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:29 by aakpinar          #+#    #+#             */
/*   Updated: 2025/09/28 13:47:11 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_error(t_game *game)
{
	ft_putstr_fd("Error: Failed to read the map file\n", 2);
	cleanup_game(game);
}

bool print_color_error(int f_count, int c_count)
{
    if (f_count == 0)
        ft_putendl_fd("Error\nMissing Floor (F) color", 2);
    else if (f_count > 1)
        ft_putendl_fd("Error\nDuplicate Floor (F) color", 2);
    else if (c_count == 0)
        ft_putendl_fd("Error\nMissing Ceiling (C) color", 2);
    else if (c_count > 1)
        ft_putendl_fd("Error\nDuplicate Ceiling (C) color", 2);
    return (false);
}