/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:26:17 by aakpinar          #+#    #+#             */
/*   Updated: 2025/09/28 12:59:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_putremain(char *putline);
char	*get_main_line(char *putline);
char	*get_read(int fd, char *putline);
char	*get_next_line(int fd);

#endif