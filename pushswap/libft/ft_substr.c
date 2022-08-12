/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:35:09 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:42:56 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;
	size_t				j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	else if (start + len < ft_strlen(s))
		str = ft_calloc(sizeof(char), (len + 1));
	else
		str = ft_calloc(sizeof(char), (ft_strlen(s) - start + 1));
	if (!str || !s)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	return (str);
}
