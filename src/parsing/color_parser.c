/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:25:00 by aakpinar          #+#    #+#             */
/*   Updated: 2025/11/02 06:45:20 by aakpinar         ###   ########.fr       */
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

bool	parse_rgb_values(char *line, int *r, int *g, int *b)
{
	char	*ptr;

	ptr = skip_spaces(line);
	*r = ft_atoi(ptr);
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	if (*ptr != ',')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	ptr++;
	*g = ft_atoi(ptr);
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	if (*ptr != ',')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	ptr++;
	*b = ft_atoi(ptr);
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	ptr = skip_spaces(ptr);
	if (*ptr != '\0' && *ptr != '\n')
		return (ft_putendl_fd("Error\nInvalid RGB format", 2), false);
	if (!is_valid_rgb(*r, *g, *b))
		return (ft_putendl_fd("Error\nRGB values must be 0-255", 2), false);
	return (true);
}
