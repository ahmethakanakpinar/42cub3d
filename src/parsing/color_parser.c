/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:25:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/09 01:41:17 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

bool	is_valid_rgb(int r, int g, int b)
{
	return (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}

char	*skip_spaces(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

static int	get_digit_count(char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count] && ft_isdigit(ptr[count]))
		count++;
	return (count);
}

bool	parse_rgb_values(char *line, int *r, int *g, int *b)
{
	char	*ptr;

	ptr = line;
	if (!parse_single_value(&ptr, r))
		return (false);
	ptr = skip_spaces(ptr);
	if (*ptr != ',')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	ptr++;
	if (!parse_single_value(&ptr, g))
		return (false);
	ptr = skip_spaces(ptr);
	if (*ptr != ',')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	ptr++;
	if (!parse_single_value(&ptr, b))
		return (false);
	ptr = skip_spaces(ptr);
	if (*ptr != '\0' && *ptr != '\n')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	if (!is_valid_rgb(*r, *g, *b))
		return (ft_putendl_fd("Error\nRGB values must be 0-255", 2), false);
	return (true);
}
