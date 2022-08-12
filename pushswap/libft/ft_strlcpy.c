/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:32:09 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:32:45 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		srclen;
	char	*str;

	str = (char *)src;
	i = 0;
	srclen = ft_strlen(str);
	if (size == 0)
		return (srclen);
	while (src[i] && i < size)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}
