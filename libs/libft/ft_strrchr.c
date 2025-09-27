/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:42:21 by aakpinar          #+#    #+#             */
/*   Updated: 2024/10/11 04:15:26 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	lst;

	lst = ft_strlen(s);
	if (s[lst] == (char)c)
	{
		return ((char *)&s[lst]);
	}
	while (lst--)
	{
		if (s[lst] == (char)c)
			return ((char *)&s[lst]);
	}
	return (NULL);
}
