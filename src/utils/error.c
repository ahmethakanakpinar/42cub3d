/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:28:29 by aakpinar          #+#    #+#             */
/*   Updated: 2025/10/07 02:01:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_error(t_game *game)
{
	ft_putstr_fd("Error: Failed to read the map file\n", 2);
	cleanup_game(game);
}

bool	print_color_error(int f_count, int c_count)
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

bool	print_texture_error(int no, int so, int we, int ea)
{
	if (no == 0)
		ft_putendl_fd("Error\nMissing North (NO) texture", 2);
	else if (no > 1)
		ft_putendl_fd("Error\nDuplicate North (NO) texture", 2);
	else if (so == 0)
		ft_putendl_fd("Error\nMissing South (SO) texture", 2);
	else if (so > 1)
		ft_putendl_fd("Error\nDuplicate South (SO) texture", 2);
	else if (we == 0)
		ft_putendl_fd("Error\nMissing West (WE) texture", 2);
	else if (we > 1)
		ft_putendl_fd("Error\nDuplicate West (WE) texture", 2);
	else if (ea == 0)
		ft_putendl_fd("Error\nMissing East (EA) texture", 2);
	else if (ea > 1)
		ft_putendl_fd("Error\nDuplicate East (EA) texture", 2);
	return (false);
}
