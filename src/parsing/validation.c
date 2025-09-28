/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 05:26:48 by aakpinar          #+#    #+#             */
/*   Updated: 2025/09/28 13:53:39 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



bool validate_map_arguments(int argc, char **argv)
{
    // Argument sayısını kontrol et
    if (argc != 2)
    {
        printf("Error: Usage: ./cub3d <map_file.cub>\n");
        return (false);
    }
    
    // Dosya uzantısını kontrol et
    const char *dot = ft_strrchr(argv[1], '.');
    if (!dot || ft_strncmp(dot, ".cub", 4) != 0)
    {
        printf("Error: Invalid file extension. Expected .cub file\n");
        return (false);
    }
    
    return (true);
}


void validate_color(char *line, int *f_count, int *c_count)
{
    int i;
    
    i = 0;
    while (line && line[i] && ft_isspace(line[i]))
        i++;
    
    if (line && line[i])
    {
        if (line[i] == 'F' && (line[i + 1] == ' ' || ft_isspace(line[i + 1])))
            (*f_count)++;
        else if (line[i] == 'C' && (line[i + 1] == ' ' || ft_isspace(line[i + 1])))
            (*c_count)++;
    }
    
    free(line);
}


bool check_color_counts(t_game *game)
{
    char *line;
    int f_count;
    int c_count;
    
    // Dosyayı aç
    game->fd_map = open(game->map_path, O_RDONLY);
    if (game->fd_map == -1)
        return (read_error(game), exit(1), false);
    
    // Renkleri kontrol et
    f_count = 0;
    c_count = 0;
    line = get_next_line(game->fd_map);
    while (line)
    {
        validate_color(line, &f_count, &c_count);
        line = get_next_line(game->fd_map);
    }
    close(game->fd_map);
    
    // F ve C sayısını kontrol et
    if (f_count != 1 || c_count != 1)
        return (print_color_error(f_count, c_count));
    return (true);
}

bool check_map_validation(t_game *game, char *path)
{
    game->map_path = path;
    if (!check_color_counts(game))
        return (cleanup_game(game), false);
    return (true);
}
