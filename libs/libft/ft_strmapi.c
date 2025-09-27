/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:45:24 by aakpinar          #+#    #+#             */
/*   Updated: 2024/11/02 11:57:46 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	len = (unsigned int)ft_strlen(s);
	str = (char *)malloc(sizeof(char) * ((int)len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[(int)i]);
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
